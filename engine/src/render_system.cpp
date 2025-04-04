#include "core/render_system.hpp"

namespace primaldawn {
    template <class RenderSystemSub>
    RenderSystem<RenderSystemSub>::RenderSystem(RenderSystemConfig config)
      : render_system_config_(std::move(config)){
    }
} // namespace primaldawn
