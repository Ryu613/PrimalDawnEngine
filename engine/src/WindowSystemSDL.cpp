#include "platform/WindowSystemSDL.h"

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
