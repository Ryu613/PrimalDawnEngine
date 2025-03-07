#pragma once

#include "SDL.h"
#include "platform/WindowSystem.hpp"

namespace pd {
    /**
    * @brief SDL2窗口的封装
    */
    class WindowSystemSDL2 : public WindowSystem {
    public:
        WindowSystemSDL2(const WindowSystem::WindowSystemOptions& windowOptions);
        virtual ~WindowSystemSDL2() = default;

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

        void* getNativeWindow() const override;
    private:
        SDL_Window* mSDLWindow{ nullptr };
    };
}
