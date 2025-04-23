#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
    class VulkanImage;
    class VulkanImageView;
    class RenderTarget {
    public:
        explicit RenderTarget(const RenderContext& render_context, VulkanImage swapchain_image);
    private:
        const RenderContext& render_context_;
        std::vector<VulkanImage> swapchain_images_;
        std::vector<VulkanImageView> swapchain_image_views_;
    };
} // namespace primaldawn
