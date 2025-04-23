#include "platform/render_system/render_system_vulkan.hpp"

#include <tuple>
#include <array>
#define VMA_IMPLEMENTATION
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#include "vk_mem_alloc.hpp"
#include "vulkan/vulkan_format_traits.hpp"

#include "primaldawn/logging.hpp"
#include "impl/platform.hpp"
#include "impl/window_system.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"
#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/render_pipeline.hpp"

namespace primaldawn {
namespace {
    const std::vector<vk::Format> depth_format_priority_list = {
        vk::Format::eD32Sfloat,
        vk::Format::eD24UnormS8Uint,
        vk::Format::eD16Unorm
    };
}
    RenderSystemVulkan::RenderSystemVulkan(const PdPlatform& platform, const config::RenderSystem& cfg)
        :PdRenderSystem(platform, cfg) {
        context_ = std::make_unique<VulkanContext>(static_cast<VulkanContext::VulkanConfig>(config_));
        setupDepthFormat();
        createAllocator();
        createSurface();
        render_context_ = std::make_unique<RenderContext>(*this);
        createSwapchainBuffers();
        createSyncObject();
        createCommandPool();
        createCommandBuffers();
        createSyncPrimitives();
        setupDepthStencil();
        setupRenderPass();
        createPipelineCache();
        setupFrameBuffer();

    }

    RenderSystemVulkan::~RenderSystemVulkan() {

    }

    void RenderSystemVulkan::BindPipeline() {

    }

    void RenderSystemVulkan::Draw() {

    }

    void RenderSystemVulkan::setupDepthFormat() {
        // setup depth format
        vk::Format depth_format{ vk::Format::eUndefined };
        for (auto& format : depth_format_priority_list) {
            vk::FormatProperties props = context_->GetPhysicalDevice().getFormatProperties(format);
            if (props.optimalTilingFeatures & vk::FormatFeatureFlagBits::eDepthStencilAttachment) {
                depth_format_ = format;
                break;
            }
        }
        if (depth_format_ == vk::Format::eUndefined) {
            throw std::runtime_error("depth format cannot be selected! ");
        }
        LOGI("depth format selected: {}", vk::to_string(depth_format_));
    }

    void RenderSystemVulkan::createAllocator() {
        vma::VulkanFunctions funcs;
        funcs.vkGetInstanceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetInstanceProcAddr;
        funcs.vkGetDeviceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetDeviceProcAddr;
        vma::AllocatorCreateInfo alloc_create_info;
        alloc_create_info.physicalDevice = context_->GetPhysicalDevice();
        alloc_create_info.device = context_->GetLogicalDevice();
        alloc_create_info.pVulkanFunctions = &funcs;
        alloc_create_info.instance = context_->GetInstance();
        vma_allocator_ = vma::createAllocator(alloc_create_info);
    }

    void RenderSystemVulkan::createSwapchainBuffers() {
        auto& images = render_context_->GetVulkanSwapchain()->GetImages();
        auto& device = context_->GetLogicalDevice();
        for (auto& swapchain_buffer : swapchain_buffers_) {
            context_->GetLogicalDevice().destroyImageView(swapchain_buffer.view);
        }
        swapchain_buffers_.clear();
        swapchain_buffers_.reserve(images.size());
        vk::ImageViewCreateInfo image_view_create_info;
        image_view_create_info.format = render_context_->GetVulkanSwapchain()->GetFormat();
        image_view_create_info.subresourceRange.aspectMask = vk::ImageAspectFlagBits::eColor;
        image_view_create_info.subresourceRange.levelCount = 1;
        image_view_create_info.subresourceRange.layerCount = 1;
        image_view_create_info.viewType = vk::ImageViewType::e2D;
        for (auto& image : images) {
            image_view_create_info.image = image;
            swapchain_buffers_.emplace_back(
                image,
                device.createImageView(image_view_create_info)
            );
        }
    }

    void RenderSystemVulkan::createCommandPool() {
        vk::CommandPoolCreateFlags flags = vk::CommandPoolCreateFlagBits::eTransient | vk::CommandPoolCreateFlagBits::eResetCommandBuffer;
        vk::CommandPoolCreateInfo command_pool_create_info(flags, context_->GetGraphicsQueueIndex());
        command_pool_ = context_->GetLogicalDevice().createCommandPool(command_pool_create_info);
    }

    void RenderSystemVulkan::createSurface() {
        void* nativeWindow = platform_.GetWindowSystem().GetNativeWindow();
        vk::Win32SurfaceCreateInfoKHR surfaceCreateInfo;
        surfaceCreateInfo.hinstance = GetModuleHandle(nullptr);
        surfaceCreateInfo.hwnd = (HWND)nativeWindow;
        // windows
        if (GetPlatform().GetOS() == OS::WINDOWS) {
            surface_ = context_->GetInstance().createWin32SurfaceKHR(surfaceCreateInfo);
        }
        else {
            throw std::runtime_error("create vulkan failed: this OS not supported!");
        }
    }

    void RenderSystemVulkan::createSyncObject() {
        semaphores_.acquired_image_ready = context_->GetLogicalDevice().createSemaphore({});
        semaphores_.render_complete = context_->GetLogicalDevice().createSemaphore({});
        vk::PipelineStageFlags submit_pipeline_stages = vk::PipelineStageFlagBits::eColorAttachmentOutput;
        submit_info_.pWaitDstStageMask = &submit_pipeline_stages;
        submit_info_.setWaitSemaphores(semaphores_.acquired_image_ready);
        submit_info_.setSignalSemaphores(semaphores_.render_complete);
    }

    void RenderSystemVulkan::createCommandBuffers() {
        vk::CommandBufferAllocateInfo alloc_info(
            command_pool_,
            vk::CommandBufferLevel::ePrimary,
            static_cast<uint32_t>(render_context_->GetRenderFrames().size())
        );
        draw_cmd_buffers_ = context_->GetLogicalDevice().allocateCommandBuffers(alloc_info);
    }

    void RenderSystemVulkan::createSyncPrimitives() {
        vk::FenceCreateInfo create_info(vk::FenceCreateFlagBits::eSignaled);
        wait_fences_.resize(draw_cmd_buffers_.size());
        for (auto& fence : wait_fences_) {
            fence = context_->GetLogicalDevice().createFence(create_info);
        }
    }

    void RenderSystemVulkan::setupDepthStencil() {
        vk::MemoryPropertyFlagBits mem_props = vk::MemoryPropertyFlagBits::eDeviceLocal;
        vk::ImageCreateInfo image_create_info(
            {},
            vk::ImageType::e2D,
            depth_format_,
            vk::Extent3D(render_context_->GetSurfaceExtent(), 1),
            1,
            1,
            vk::SampleCountFlagBits::e1,
            vk::ImageTiling::eOptimal,
            vk::ImageUsageFlagBits::eDepthStencilAttachment | vk::ImageUsageFlagBits::eTransferSrc
        );
       vk::Image image = context_->GetLogicalDevice().createImage(image_create_info);
       vk::MemoryRequirements mem_req = context_->GetLogicalDevice().getImageMemoryRequirements(image);
       vk::MemoryAllocateInfo mem_alloc_info(
            mem_req.size,
            context_->GetMemoryType(mem_req.memoryTypeBits, mem_props)
       );
       vk::DeviceMemory mem = context_->GetLogicalDevice().allocateMemory(mem_alloc_info);
       context_->GetLogicalDevice().bindImageMemory(image, mem, 0);
       depth_stencil_.image = image;
       depth_stencil_.mem = mem;
       vk::ImageAspectFlags aspect_mask = vk::ImageAspectFlagBits::eDepth;
       // Stencil aspect should only be set on depth + stencil formats
       if ((vk::componentCount(depth_format_) == 2) && (strcmp(vk::componentName(depth_format_, 0), "D") == 0) &&
           (strcmp(vk::componentName(depth_format_, 1), "S") == 0)) {
           aspect_mask |= vk::ImageAspectFlagBits::eStencil;
       }
       // create depth image view
       vk::ImageViewCreateInfo image_view_create_info;
       image_view_create_info.image = depth_stencil_.image;
       image_view_create_info.viewType = vk::ImageViewType::e2D;
       image_view_create_info.format = depth_format_;
       image_view_create_info.subresourceRange.aspectMask = aspect_mask;
       image_view_create_info.subresourceRange.baseMipLevel = 0;
       image_view_create_info.subresourceRange.levelCount = 1;
       image_view_create_info.subresourceRange.baseArrayLayer = 0;
       image_view_create_info.subresourceRange.layerCount = 1;
       depth_stencil_.view = context_->GetLogicalDevice().createImageView(image_view_create_info);
    }

    void RenderSystemVulkan::setupRenderPass() {
        std::array<vk::AttachmentDescription, 2> atts;
        // color
        atts[0].format = render_context_->GetFormat();
        atts[0].samples = vk::SampleCountFlagBits::e1;
        atts[0].loadOp = vk::AttachmentLoadOp::eClear;
        atts[0].storeOp = vk::AttachmentStoreOp::eStore;
        atts[0].stencilLoadOp = vk::AttachmentLoadOp::eDontCare;
        atts[0].stencilStoreOp = vk::AttachmentStoreOp::eDontCare;
        atts[0].initialLayout = vk::ImageLayout::eUndefined;
        atts[0].finalLayout = vk::ImageLayout::ePresentSrcKHR;
        // depth
        atts[1].format = depth_format_;
        atts[1].samples = vk::SampleCountFlagBits::e1;
        atts[1].loadOp = vk::AttachmentLoadOp::eClear;
        atts[1].storeOp = vk::AttachmentStoreOp::eDontCare;
        atts[1].stencilLoadOp = vk::AttachmentLoadOp::eClear;
        atts[1].stencilStoreOp = vk::AttachmentStoreOp::eDontCare;
        atts[1].initialLayout = vk::ImageLayout::eUndefined;
        atts[1].finalLayout = vk::ImageLayout::eDepthStencilAttachmentOptimal;
        vk::AttachmentReference color_ref(0, vk::ImageLayout::eColorAttachmentOptimal);
        vk::AttachmentReference depth_ref(1, vk::ImageLayout::eDepthStencilAttachmentOptimal);
        // why color_ref is not pointer, but depth_ref is?
        vk::SubpassDescription subpass_desc({}, vk::PipelineBindPoint::eGraphics, {}, color_ref, {}, &depth_ref);

        std::array<vk::SubpassDependency, 2> deps;

        deps[0].srcSubpass = VK_SUBPASS_EXTERNAL;
        deps[0].dstSubpass = 0;
        deps[0].srcStageMask = vk::PipelineStageFlagBits::eBottomOfPipe;
        deps[0].dstStageMask = vk::PipelineStageFlagBits::eColorAttachmentOutput
            | vk::PipelineStageFlagBits::eEarlyFragmentTests
            | vk::PipelineStageFlagBits::eLateFragmentTests;
        deps[0].srcAccessMask = vk::AccessFlagBits::eNoneKHR;
        deps[0].dstAccessMask = vk::AccessFlagBits::eColorAttachmentRead
            | vk::AccessFlagBits::eColorAttachmentWrite
            | vk::AccessFlagBits::eDepthStencilAttachmentRead
            | vk::AccessFlagBits::eDepthStencilAttachmentWrite;
        deps[0].dependencyFlags = vk::DependencyFlagBits::eByRegion;
        deps[1].srcSubpass = 0;
        deps[1].dstSubpass = VK_SUBPASS_EXTERNAL;
        deps[1].srcStageMask = vk::PipelineStageFlagBits::eColorAttachmentOutput
            | vk::PipelineStageFlagBits::eEarlyFragmentTests
            | vk::PipelineStageFlagBits::eLateFragmentTests;
        deps[1].dstStageMask = vk::PipelineStageFlagBits::eBottomOfPipe;
        deps[1].srcAccessMask = vk::AccessFlagBits::eColorAttachmentRead
            | vk::AccessFlagBits::eColorAttachmentWrite
            | vk::AccessFlagBits::eDepthStencilAttachmentRead
            | vk::AccessFlagBits::eDepthStencilAttachmentWrite;
        deps[1].dstAccessMask = vk::AccessFlagBits::eMemoryRead;
        deps[1].dependencyFlags = vk::DependencyFlagBits::eByRegion;

        vk::RenderPassCreateInfo create_info(
            {},
            atts,
            subpass_desc,
            deps
        );
        render_pass_ = context_->GetLogicalDevice().createRenderPass(create_info);
    }

    void RenderSystemVulkan::createPipelineCache() {
        pipeline_cache_ = context_->GetLogicalDevice().createPipelineCache({});
    }

    void RenderSystemVulkan::setupFrameBuffer() {
        std::array<vk::ImageView, 2> atts;
        atts[1] = depth_stencil_.view;
        auto& extent = render_context_->GetSurfaceExtent();
        vk::FramebufferCreateInfo frame_buffer_create_info(
            {},
            render_pass_,
            atts,
            extent.width,
            extent.height,
            1
        );
        // destroy existing frame buffer
        for (auto& frame_buffer : frame_buffers_) {
            context_->GetLogicalDevice().destroyFramebuffer(frame_buffer);
        }
        frame_buffers_.clear();
        frame_buffers_.reserve(swapchain_buffers_.size());
        for (auto& buffer : swapchain_buffers_) {
            atts[0] = buffer.view;
            frame_buffers_.emplace_back(context_->GetLogicalDevice().createFramebuffer(frame_buffer_create_info));
        }
    }

    const VulkanContext& RenderSystemVulkan::GetContext() const {
        return *context_;
    }

    const vk::SurfaceKHR& RenderSystemVulkan::GetSurface() const {
        return surface_;
    }

    const vk::Format& RenderSystemVulkan::GetDepthFormat() const {
        return depth_format_;
    }

    const vma::Allocator& RenderSystemVulkan::GetMemoryAllocator() const {
        return vma_allocator_;
    }
} // namespace primaldawn
