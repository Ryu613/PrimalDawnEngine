#include "impl/render_system.hpp"

namespace primaldawn {
    RenderSystem::RenderSystem(config::RenderSystem config)
      : config_(std::move(config)){
    }
} // namespace primaldawn
