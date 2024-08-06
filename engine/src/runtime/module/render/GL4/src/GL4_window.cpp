#include "GL4_window.hpp"

namespace PrimalDawn {
    GL4Window::~GL4Window() {
        glfwDestroyWindow(thisWindow);
        glfwTerminate();
    }

    bool GL4Window::initialize(GLFWWIndowCreateInfo createInfo) {
        //初始化glfw库，若失败则退出
        if (!glfwInit()) {
            return false;
        }
        // 实例化glfwWindow，指定计算机必须与OpenGL 4.3兼容
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        thisWidth = createInfo.width;
        thisHeight = createInfo.height;
        // 创建glfw窗口，参数为（宽，高，标题，允许全屏显示，资源共享）
        thisWindow = glfwCreateWindow(thisWidth, thisHeight, createInfo.title, NULL, NULL);
        if (!thisWindow) {
            glfwTerminate();
            return false;
        }
        
        // 把glfw的窗口和当前OpenGL的上下文关联起来
        glfwMakeContextCurrent(thisWindow);

        while (!glfwWindowShouldClose(thisWindow)) {
            // 用glfw初始化后经过的时间，保证再不同计算机上以相同速度播放
            //display(thisWindow, glfwGetTime());
            glfwSwapBuffers(thisWindow);
            glfwPollEvents();
        }
    }
}