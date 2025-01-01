#ifndef DAWN_PRIMALDAWN_ENGINE_SDLWINDOW_H
#define DAWN_PRIMALDAWN_ENGINE_SDLWINDOW_H

#include "platform/Window.h"
#include "SDL.h"

namespace pd {
    /**
    * @brief SDL2窗口的封装
    */
    class SDLWindow : public Window {
    public:
        SDLWindow(const Window::WindowOptions& windowOptions);
        virtual ~SDLWindow() = default;

        /**
        * @brief 用于检查窗口是否应该被关闭
        */
        virtual bool shouldClose() override;

        /**
        * @brief 处理窗口事件
        */
        virtual void doEvents() override;

        /**
        * @brief 关闭窗口
        */
        virtual void close() override;
    private:
        SDL_Window* mSDLWindow{ nullptr };
    };
}

#endif
