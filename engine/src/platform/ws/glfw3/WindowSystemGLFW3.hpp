#pragma once

#include "platform/WindowSystem.hpp"

class GLFWwindow;
namespace pd {
    class WindowSystemGLFW3 : public WindowSystem {
    public:
        WindowSystemGLFW3(const WindowSystem::WindowSystemOptions& windowOptions);
        ~WindowSystemGLFW3() = default;

        virtual bool shouldClose() override;

        virtual void doEvents() override;

        virtual void close() override;

        void* getNativeWindow() const override;
    private:
        GLFWwindow* mGLFWWindow{ nullptr };

        inline static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    };
}
