#include "platform/render_system/vulkan/render_frame.hpp"

#include "platform/render_system/vulkan/render_context.hpp"
#include "platform/render_system/vulkan/render_target.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

namespace primaldawn {
    RenderFrame::RenderFrame(const RenderContext& render_context, const vk::Image& swapchain_image)
      : render_context_(render_context) {
        render_target_ = std::make_unique<RenderTarget>(render_context_, swapchain_image);
    }
} // namespace primaldawn
