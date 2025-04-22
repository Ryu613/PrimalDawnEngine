#include "platform/render_system/vulkan/render_target.hpp"

#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

namespace primaldawn {
    RenderTarget::RenderTarget(const RenderContext& render_context, const vk::Image& swapchain_image)
      : render_context_(render_context) {
        swapchain_images_.push_back(swapchain_image);
        auto& device = render_context_.GetVulkanContext()->GetLogicalDevice();
        auto swapchain = render_context_.GetVulkanSwapchain();
        //depth image
        auto depth_format = render_context_.GetDepthFormat();
        vk::ImageCreateInfo image_create_info;
        image_create_info.samples = vk::SampleCountFlagBits::e1;
        image_create_info.usage = vk::ImageUsageFlagBits::eDepthStencilAttachment
            | vk::ImageUsageFlagBits::eTransientAttachment;
        image_create_info.format = depth_format;
        image_create_info.extent = vk::Extent3D{ render_context_.GetSurfaceExtent(), 1 };
        // should value extent to choose image type
        image_create_info.imageType = vk::ImageType::e2D;
        image_create_info.arrayLayers = 1;
        image_create_info.mipLevels = 1;
        image_create_info.tiling = vk::ImageTiling::eOptimal;
        auto depth_image = device.createImage(image_create_info);
        swapchain_images_.emplace_back(depth_image);
        // create image view
        vk::ImageViewCreateInfo image_view_create_info;
        image_view_create_info.format = swapchain->GetFormat();
        image_view_create_info.subresourceRange.aspectMask = vk::ImageAspectFlagBits::eColor;
        image_view_create_info.subresourceRange.baseMipLevel = 0,
        image_view_create_info.subresourceRange.levelCount = 1;
        image_view_create_info.subresourceRange.baseArrayLayer = 0,
        image_view_create_info.subresourceRange.layerCount = 1;
        image_view_create_info.viewType = vk::ImageViewType::e2D;
        image_view_create_info.image = swapchain_image;
        swapchain_image_views_.emplace_back(device.createImageView(image_view_create_info));
        //depth image view
        image_view_create_info.image = depth_image;
        image_view_create_info.subresourceRange.aspectMask = vk::ImageAspectFlagBits::eDepth;
        image_view_create_info.format = depth_format;
        swapchain_image_views_.emplace_back(device.createImageView(image_view_create_info));
        // TODO: allocate and bind memory
        VmaAllocationCreateInfo alloc_create_info{
            .flags = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT,
            .usage = VMA_MEMORY_USAGE_AUTO
        };
    }
} // namespace primaldawn
