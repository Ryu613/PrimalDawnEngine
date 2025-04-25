#pragma once

#include "platform/render_system/vulkan/render_context.hpp"

namespace primaldawn {
    class VulkanImage;
    class VulkanImageView;
    class RenderTarget {
    public:
        explicit RenderTarget(const RenderContext& render_context, VulkanImage&& swapchain_image);
        ~RenderTarget();
    private:
        const RenderContext& render_context_;
        std::vector<VulkanImage> swapchain_images_;
        std::vector<VulkanImageView> swapchain_image_views_;
    public:
        RenderTarget(const RenderTarget&) = delete;
        RenderTarget(RenderTarget&&) noexcept = delete;
        RenderTarget& operator=(const RenderTarget&) = delete;
        RenderTarget& operator=(RenderTarget&&) noexcept = delete;
    };
} // namespace primaldawn
