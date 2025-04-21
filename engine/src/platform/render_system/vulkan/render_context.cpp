#include "platform/render_system/vulkan/render_context.hpp"

#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"
#include "platform/render_system/vulkan/render_frame.hpp"
#include "platform/render_system/vulkan/render_target.hpp"

namespace primaldawn {
    RenderContext::RenderContext(const RenderSystemVulkan& render_system_vulkan)
        : render_system_vulkan_(render_system_vulkan) {
        // create swapchain
        swapchain_ = std::make_unique<VulkanSwapchain>(render_system_vulkan_);
        // fill up render frames
        for (auto& image : swapchain_->GetImages()) {
            frames_.emplace_back(std::make_unique<RenderFrame>(*this));
        }
        render_system_vulkan_.GetContext()->GetLogicalDevice().waitIdle();
        vk::ImageViewCreateInfo image_view_create_info;
        image_view_create_info.format = swapchain_->GetProps().surface_format.format;
        image_view_create_info.subresourceRange.aspectMask = vk::ImageAspectFlagBits::eColor;
        image_view_create_info.subresourceRange.levelCount = 1;
        image_view_create_info.subresourceRange.layerCount = 1;
        image_view_create_info.viewType = vk::ImageViewType::e2D;
        
        auto& device = render_system_vulkan_.GetContext()->GetLogicalDevice();
        for (int i = 0; i < images.size(); ++i) {
            image_view_create_info.image = images[i].image;
            images[i].image_views.emplace_back(device.createImageView(image_view_create_info));
            // TODO depth image view
            frames_.emplace_back(std::make_unique<RenderFrame>());
        }
        
    }
} // namespace primaldawn
