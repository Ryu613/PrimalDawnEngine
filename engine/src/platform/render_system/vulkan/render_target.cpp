#include "platform/render_system/vulkan/render_target.hpp"

#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

namespace primaldawn {
    RenderTarget::RenderTarget(const RenderContext& render_context, const vk::Image& swapchain_image)
      : render_context_(render_context) {
        swapchain_images_.push_back(swapchain_image);
        // create image view
        auto& device = render_context_.GetVulkanContext()->GetLogicalDevice();
        auto swapchain = render_context_.GetVulkanSwapchain();
        vk::ImageViewCreateInfo image_view_create_info;
        image_view_create_info.format = swapchain->GetProps().surface_format.format;
        image_view_create_info.subresourceRange.aspectMask = vk::ImageAspectFlagBits::eColor;
        image_view_create_info.subresourceRange.levelCount = 1;
        image_view_create_info.subresourceRange.layerCount = 1;
        image_view_create_info.viewType = vk::ImageViewType::e2D;
        image_view_create_info.image = swapchain_image;
        swapchain_image_views_.emplace_back(device.createImageView(image_view_create_info));
        //TODO depth image
    }
} // namespace primaldawn
