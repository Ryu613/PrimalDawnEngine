#include "platform/render_system/vulkan/render_target.hpp"

#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_image.hpp"
#include "platform/render_system/vulkan/vulkan_image_view.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

namespace primaldawn {
    RenderTarget::RenderTarget(const RenderContext& render_context, VulkanImage&& swapchain_image)
      : render_context_(render_context) {
        auto image_depth_ci = swapchain_image.GetCreateInfo();
        swapchain_images_.emplace_back(std::move(swapchain_image));
        // create depth image
        auto& device = render_context_.GetVulkanContext().GetLogicalDevice();
        auto& swapchain = render_context_.GetVulkanSwapchain();
        //depth image
        auto& depth_format = render_context_.GetDepthFormat();
        image_depth_ci.usage = vk::ImageUsageFlagBits::eDepthStencilAttachment
            | vk::ImageUsageFlagBits::eTransientAttachment;
        image_depth_ci.format = depth_format;
        VulkanImage depth_image(render_context_.GetRenderSystem(), image_depth_ci);
        swapchain_images_.emplace_back(std::move(depth_image));
        // create image view
        for (auto& image : swapchain_images_) {
            swapchain_image_views_.emplace_back(render_context_.GetRenderSystem(), image, vk::ImageViewType::e2D);
        }
    }

    RenderTarget::~RenderTarget() {

    }
} // namespace primaldawn
