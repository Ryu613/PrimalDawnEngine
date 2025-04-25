#include "impl/window_system.hpp"

#include "impl/logging.hpp"

namespace primaldawn {
    PdWindowSystem::PdWindowSystem(const config::WindowSystem& config)
      : config_(config){
        LOGI("initializing window system...")
    }

    PdWindowSystem::~PdWindowSystem() {
        LOGI("destroying window system...")
    }

    void PdWindowSystem::DoEvents() {

    }

    const config::WindowSystem& PdWindowSystem::GetConfig() const {
        return config_;
    }
}
