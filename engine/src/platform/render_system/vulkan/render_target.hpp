#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
    class RenderTarget {
    public:
        explicit RenderTarget(const RenderContext& render_context, const vk::Image& swapchain_image);
    private:
        const RenderContext& render_context_;
        std::vector<vk::Image> swapchain_images_;
        std::vector<vk::ImageView> swapchain_image_views_;
    };
} // namespace primaldawn
