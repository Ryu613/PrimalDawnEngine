#include "platform/SDLWindow.h"

using namespace pd;

SDLWindow::SDLWindow(const Window::WindowOptions& windowOptions) :
    Window(windowOptions){
    // 先把sdl2的事件系统初始化
    SDL_Init(SDL_INIT_EVENTS);
    // 创建窗口
    const int x = SDL_WINDOWPOS_CENTERED;
    const int y = SDL_WINDOWPOS_CENTERED;
    unsigned int windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
    mSDLWindow = SDL_CreateWindow(mWindowOptions.title.c_str(),
        x,
        y,
        (int)mWindowOptions.extent.width,
        (int)mWindowOptions.extent.height,
        windowFlags);
}

bool SDLWindow::shouldClose() {
    return mClosed;
}

void SDLWindow::doEvents() {

}

void SDLWindow::close() {

}
