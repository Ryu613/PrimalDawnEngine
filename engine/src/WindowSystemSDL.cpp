#include "platform/WindowSystemSDL.h"
#include <SDL_syswm.h>
#include "core/util/Logging.h"

using namespace pd;

WindowSystemSDL::WindowSystemSDL(const WindowSystem::WindowSystemOptions& windowSystemOptions) :
    WindowSystem(windowSystemOptions){
    // 先把sdl2的事件系统初始化
    SDL_Init(SDL_INIT_EVENTS);
    // 创建窗口
    const int x = SDL_WINDOWPOS_CENTERED;
    const int y = SDL_WINDOWPOS_CENTERED;
    unsigned int windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
    mSDLWindow = SDL_CreateWindow(mWindowSystemOptions.title.c_str(),
        x,
        y,
        (int)mWindowSystemOptions.extent.width,
        (int)mWindowSystemOptions.extent.height,
        windowFlags);
}

bool WindowSystemSDL::shouldClose() {
    return mClosed;
}

void WindowSystemSDL::doEvents() {
}

void WindowSystemSDL::close() {

}

void* WindowSystemSDL::getNativeWindow() const {
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo(mSDLWindow, &wmi)) {
        LOG_ERROR("SDL获取原生窗口系统信息失败!");
        throw std::runtime_error("SDLWindow get native Window info error!");
    }
    HWND win = (HWND)wmi.info.win.window;
    return (void*)win;
}
