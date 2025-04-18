#include "impl/Platform.hpp"

#include <memory>
#include <stdexcept>

#include "primaldawn/logging.hpp"
#if defined(PRIMALDAWN_WSI_TYPE_SDL2)
#include "platform/window_system/window_system_sdl2.hpp"
#elif defined(PRIMALDAWN_WSI_TYPE_GLFW)
#include "platform/window_system/window_system_glfw3.hpp"
#else
#endif

namespace primaldawn {
    PdPlatform::~PdPlatform() {
        LOGI("destroying platform")
    }

    PdPlatform::PdPlatform(config::Platform config)
      : config_(std::move(config)){
    #if defined(PRIMALDAWN_WSI_TYPE_SDL2)
        LOGI("WindowSystem - SDL2")
        if (config_.window_system_type == WindowSystemType::SDL2) {
            window_system_ = std::make_unique<WindowSystemSdl2>(config_.window_system);
        }
        else {
            throw std::runtime_error("init Platform failed, Window System config error!");
        }
    #elif defined(PRIMALDAWN_WSI_TYPE_GLFW)
        LOGI("WindowSystem - GLFW3")
        if (config_.window_system_type == WindowSystemType::GLFW3) {
            window_system_ = std::make_unique<WindowSystemGlfw3>(config_.window_system);
        }
        else {
            throw std::runtime_error("init Platform failed, Window System config error!");
        }
    #else
        throw std::runtime_error("init Platform failed, Unknown Platform!");
    #endif
    }

    PdWindowSystem* PdPlatform::GetWindowSystem() const {
        return window_system_.get();
    }
} // namespace primaldawn
