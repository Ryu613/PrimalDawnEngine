#include "impl/window_system.hpp"

#include "primaldawn/logging.hpp"

namespace primaldawn {
    PdWindowSystem::PdWindowSystem(config::WindowSystem config)
      : config_(std::move(config)){
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
