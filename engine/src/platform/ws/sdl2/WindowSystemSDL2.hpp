#pragma once
#include "platform/WindowSystem.hpp"
#include "SDL.h"

namespace pd {
    /**
    * @brief SDL2窗口的封装
    */
    class WindowSystemSDL2 : public WindowSystem {
    public:
        WindowSystemSDL2(const WindowSystem::WindowSystemOptions& windowOptions);
        ~WindowSystemSDL2() = default;

        virtual bool shouldClose() override;

        virtual void doEvents() override;

        virtual void close() override;

        virtual void processInput() override;

        void* getNativeWindow() const override;
    private:
        SDL_Window* mSDLWindow{ nullptr };
    };
}
