#include "platform/window_system/window_system_sdl2.hpp"

namespace primaldawn {
    WindowSystemSdl2::WindowSystemSdl2(config::WindowSystem cfg)
      : PdWindowSystem(std::move(cfg)) {
        SDL_Init(SDL_INIT_EVENTS);
        // 创建窗口
        const int x = SDL_WINDOWPOS_CENTERED;
        const int y = SDL_WINDOWPOS_CENTERED;
        unsigned int windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
        mSDLWindow = SDL_CreateWindow(config_.title.c_str(),
            x,
            y,
            static_cast<int>(config_.extent.width),
            static_cast<int>(config_.extent.height),
            windowFlags);
    }

    WindowSystemSdl2::~WindowSystemSdl2() {

    }

    bool WindowSystemSdl2::ShouldClose() {
        return closed_;
    }

    void WindowSystemSdl2::DoEvents() {

    }

    void WindowSystemSdl2::Close() {

    }
} // namespace primaldawn
