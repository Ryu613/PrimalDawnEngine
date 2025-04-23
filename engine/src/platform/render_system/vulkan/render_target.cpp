#include "platform/render_system/vulkan/render_target.hpp"

#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_image.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

namespace primaldawn {
    RenderTarget::RenderTarget(const RenderContext& render_context, VulkanImage swapchain_image)
      : render_context_(render_context) {
        auto image_depth_ci = swapchain_image.GetCreateInfo();
        swapchain_images_.emplace_back(std::move(swapchain_image));
        // create depth image
        auto& device = render_context_.GetVulkanContext()->GetLogicalDevice();
        auto swapchain = render_context_.GetVulkanSwapchain();
        //depth image
        auto& depth_format = render_context_.GetDepthFormat();
        image_depth_ci.usage = vk::ImageUsageFlagBits::eDepthStencilAttachment
            | vk::ImageUsageFlagBits::eTransientAttachment;
        image_depth_ci.format = depth_format;
        VulkanImage depth_image(render_context_.GetRenderSystem(), image_depth_ci);
        swapchain_images_.emplace_back(std::move(depth_image));
        // create image view
        for (auto& image : swapchain_images_) {
            swapchain_image_views_.emplace_back(image, vk::ImageViewType::e2D);
        }
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
    }
} // namespace primaldawn
