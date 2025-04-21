#include "platform/render_system/vulkan/render_frame.hpp"

#include "platform/render_system/vulkan/render_context.hpp"

namespace primaldawn {
    RenderFrame::RenderFrame(const RenderContext& render_context)
      : render_context_(render_context) {

    }
} // namespace primaldawn
