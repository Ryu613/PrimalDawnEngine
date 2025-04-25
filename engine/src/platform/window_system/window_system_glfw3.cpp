#include "platform/window_system/window_system_glfw3.hpp"

#include "impl/logging.hpp"

namespace primaldawn {

    /**
    * @brief 初始化GLFW3和GLAD
    */
    WindowSystemGlfw3::WindowSystemGlfw3(config::WindowSystem wsConfig)
      : PdWindowSystem(std::move(wsConfig)) {
        LOGI("initializing GLFW3...")
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfw_window_ = glfwCreateWindow(
            config_.extent.width,
            config_.extent.height,
            config_.title.c_str(),
            nullptr,
            nullptr);
        if (glfw_window_ == nullptr) {
            LOGE("failed to create GLFW window")
            glfwTerminate();
            throw std::runtime_error("failed to create GLFW window");
        }
        glfwMakeContextCurrent(glfw_window_);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LOGE("failed to create GLFW window")
            throw std::runtime_error("failed to initialize GLAD");
        }

        glViewport(0, 0, config_.extent.width, config_.extent.height);

        glfwSetFramebufferSizeCallback(glfw_window_, FramebufferSizeCallback);
        closed_ = false;
    }

    WindowSystemGlfw3::~WindowSystemGlfw3() {

    }

    bool WindowSystemGlfw3::ShouldClose() {
        return glfwWindowShouldClose(glfw_window_);
    }

    void WindowSystemGlfw3::DoEvents() {
        glfwSwapBuffers(glfw_window_);
        glfwPollEvents();
    }

    void WindowSystemGlfw3::Close() {
        glfwTerminate();
        closed_ = true;
    }

    void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }
} // namespace primaldawn
