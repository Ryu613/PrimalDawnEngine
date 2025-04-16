#include "platform/window_system/window_system_sdl2.hpp"

#include <SDL_syswm.h>

#include "primaldawn/logging.hpp"

namespace primaldawn {
    WindowSystemSdl2::WindowSystemSdl2(config::WindowSystem cfg)
      : PdWindowSystem(std::move(cfg)) {
        SDL_Init(SDL_INIT_EVENTS);
        // 创建窗口
        const int x = SDL_WINDOWPOS_CENTERED;
        const int y = SDL_WINDOWPOS_CENTERED;
        unsigned int windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
        sdl_window_ = SDL_CreateWindow(config_.title.c_str(),
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

    void* WindowSystemSdl2::GetNativeWindow() const {
        SDL_SysWMinfo wmi;
        SDL_VERSION(&wmi.version);
        if (!SDL_GetWindowWMInfo(mSDLWindow, &wmi)) {
            LOGE("SDL2 get native window ptr fail !");
            throw std::runtime_error("SDLWindow get native Window info error!");
        }
        HWND win = (HWND)wmi.info.win.window;
        return (void*)win;
    }
} // namespace primaldawn
