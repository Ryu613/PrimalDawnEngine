#include "impl/render_system.hpp"

#include "primaldawn/logging.hpp"

namespace primaldawn {

    PdRenderSystem::PdRenderSystem(const PdPlatform& platform, const config::RenderSystem& config)
      : platform_(platform),
        config_(config) {
        LOGI("initializing render system...")
    }

    PdRenderSystem::~PdRenderSystem() {
        LOGI("destroying render system...")
    }

    void PdRenderSystem::BindPipeline() {}

    void PdRenderSystem::Draw() {}

    const PdPlatform& PdRenderSystem::GetPlatform() const {
        return platform_;
    }

} // namespace primaldawn
