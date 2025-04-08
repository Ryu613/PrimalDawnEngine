#include "impl/render_system.hpp"

#include "primaldawn/logging.hpp"

namespace primaldawn {

    PdRenderSystem::PdRenderSystem(config::RenderSystem config)
      : config_(std::move(config)) {
        LOGI("initializing render system...")
    }

    PdRenderSystem::~PdRenderSystem() {
        LOGI("destroying render system...")
    }

    void PdRenderSystem::bindPipeline() {

    }

    void PdRenderSystem::draw() {

    }

} // namespace primaldawn
