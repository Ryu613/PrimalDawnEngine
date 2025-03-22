#include "WindowSystemGLFW3.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/Logging.hpp"

namespace pd {
    WindowSystemGLFW3::WindowSystemGLFW3(const WindowSystem::WindowSystemOptions& windowOptions) :
        WindowSystem(windowOptions) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        mGLFWWindow = glfwCreateWindow(
            windowOptions.extent.width,
            windowOptions.extent.height,
            windowOptions.title.c_str(),
            nullptr,
            nullptr);
        if (mGLFWWindow == nullptr) {
            LOG_ERROR("failed to create GLFW window")
            glfwTerminate();
            throw std::runtime_error("failed to create GLFW window");
        }
        glfwMakeContextCurrent(mGLFWWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOG_ERROR("failed to create GLFW window")
            throw std::runtime_error("failed to initialize GLAD");
        }

        glViewport(0, 0, windowOptions.extent.width, windowOptions.extent.height);

        glfwSetFramebufferSizeCallback(mGLFWWindow, framebufferSizeCallback);

        while (!glfwWindowShouldClose(mGLFWWindow))
        {
            glfwSwapBuffers(mGLFWWindow);
            glfwPollEvents();
        }
    }

    void WindowSystemGLFW3::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    bool WindowSystemGLFW3::shouldClose() {
        return mClosed;
    }

    void WindowSystemGLFW3::doEvents() {
    }

    void WindowSystemGLFW3::close() {
    }
    void* WindowSystemGLFW3::getNativeWindow() const {
        return nullptr;
    }
}
