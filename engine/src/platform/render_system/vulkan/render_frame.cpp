#include "platform/render_system/vulkan/render_frame.hpp"

#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/render_target.hpp"
#include "platform/render_system/vulkan/vulkan_image.hpp"

namespace primaldawn {
    RenderFrame::RenderFrame(const RenderContext& render_context, VulkanImage&& swapchain_image)
      : render_context_(render_context) {
        render_target_ = std::make_unique<RenderTarget>(render_context_, std::move(swapchain_image));
    }
} // namespace primaldawn
