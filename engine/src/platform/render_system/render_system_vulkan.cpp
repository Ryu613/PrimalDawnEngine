#include "platform/render_system/render_system_vulkan.hpp"

#define VMA_IMPLEMENTATION
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#include "vma/vk_mem_alloc.h"

#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "impl/platform.hpp"
#include "impl/window_system.hpp"

namespace primaldawn {
    RenderSystemVulkan::RenderSystemVulkan(const PdPlatform* platform, config::RenderSystem cfg)
        :PdRenderSystem(std::move(cfg)),
         platform_(platform) {
        // ref:
        // x vulkanPlatform
        // x resourceManager
        // (delay) vulkanSwapchain
        // (delay) vulkanRenderTarget
        // (delay) VulkanRenderPass
        // √ VmaAllocator
        // (optional) VkDebugReportCallbackExt
        // √ VulkanContext
        // √ VulkanCommands(command buffer pool)
        // √ VulkanPipelineLayoutCache
        // √ VulkanPipelineCache
        // √ VulkanStagePool
        // √ VulkanFboCache
        // √ VulkanSamplerCache
        // √ VulkanBlitter
        // √ VulkanReadPixels
        // √ VulkanDescriptorSetManager
        // √ VulkanQueryManager
        // (delay) struct BoundPipeline
        // (delay) struct RenderPassFboInfo
        // √ other params

        context_ = std::make_unique<VulkanContext>(static_cast<VulkanContext::VulkanConfig>(cfg));
        createAllocator();
        createCommandPool();
        createSurface();
        swapchain_ = std::make_unique<VulkanSwapchain>(*this);
    }

    RenderSystemVulkan::~RenderSystemVulkan() {

    }

    void RenderSystemVulkan::BindPipeline() {

    }

    void RenderSystemVulkan::Draw() {

    }

    void RenderSystemVulkan::createAllocator() {
        VmaVulkanFunctions const funcs{
            .vkGetInstanceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetInstanceProcAddr,
            .vkGetDeviceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetDeviceProcAddr,
        };
        VmaAllocatorCreateInfo const allocatorInfo{
            .physicalDevice = context_->GetPhysicalDevice(),
            .device = context_->GetLogicalDevice(),
            .pVulkanFunctions = &funcs,
            .instance = context_->GetInstance(),
        };
        vmaCreateAllocator(&allocatorInfo, &vma_allocator_);
    }

    void RenderSystemVulkan::createCommandPool() {
        vk::CommandPoolCreateFlags flags = vk::CommandPoolCreateFlagBits::eTransient | vk::CommandPoolCreateFlagBits::eResetCommandBuffer;
        vk::CommandPoolCreateInfo command_pool_create_info(flags, context_->GetGraphicsQueueIndex());
        command_pool_ = context_->GetLogicalDevice().createCommandPool(command_pool_create_info);
    }

    void RenderSystemVulkan::createSurface() {
        void* nativeWindow = platform_->GetWindowSystem()->GetNativeWindow();
        vk::Win32SurfaceCreateInfoKHR surfaceCreateInfo;
        surfaceCreateInfo.hinstance = GetModuleHandle(nullptr);
        surfaceCreateInfo.hwnd = (HWND)nativeWindow;
        // windows
        surface_ = context_->GetInstance().createWin32SurfaceKHR(surfaceCreateInfo);
        if (!surface_) {
            throw std::runtime_error("failed to create window surface");
        }
    }

    const PdPlatform* RenderSystemVulkan::GetPlatform() const {
        return platform_;
    }
    const VulkanContext* RenderSystemVulkan::GetContext() const {
        return context_.get();
    }

    const vk::SurfaceKHR& RenderSystemVulkan::GetSurface() const {
        return surface_;
    }

    const VulkanSwapchain* RenderSystemVulkan::GetSwapchain() const {
        return swapchain_.get();
    }
} // namespace primaldawn
