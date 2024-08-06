#include "GL4_window.hpp"

namespace PrimalDawn {
    GL4Window::~GL4Window() {
        glfwDestroyWindow(thisWindow);
        glfwTerminate();
    }

    bool GL4Window::initialize(GLFWWIndowCreateInfo createInfo) {
        //��ʼ��glfw�⣬��ʧ�����˳�
        if (!glfwInit()) {
            return false;
        }
        // ʵ����glfwWindow��ָ�������������OpenGL 4.3����
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        thisWidth = createInfo.width;
        thisHeight = createInfo.height;
        // ����glfw���ڣ�����Ϊ�����ߣ����⣬����ȫ����ʾ����Դ����
        thisWindow = glfwCreateWindow(thisWidth, thisHeight, createInfo.title, NULL, NULL);
        if (!thisWindow) {
            glfwTerminate();
            return false;
        }
        
        // ��glfw�Ĵ��ں͵�ǰOpenGL�������Ĺ�������
        glfwMakeContextCurrent(thisWindow);

        while (!glfwWindowShouldClose(thisWindow)) {
            // ��glfw��ʼ���󾭹���ʱ�䣬��֤�ٲ�ͬ�����������ͬ�ٶȲ���
            //display(thisWindow, glfwGetTime());
            glfwSwapBuffers(thisWindow);
            glfwPollEvents();
        }
    }
}