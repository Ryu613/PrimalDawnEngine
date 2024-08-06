#pragma once
#include <GLFW/glfw3.h>

namespace PrimalDawn {
    struct GLFWWIndowCreateInfo {
        int width{ 1280 };
        int height{ 720 };
        const char* title{ "Primal Dawn Engine" };
        bool is_fullScreen{ false };
    };
    class GL4Window {
    public:
        GL4Window() = default;
        ~GL4Window();
        bool initialize(GLFWWIndowCreateInfo createInfo);
    private:
        GLFWwindow* thisWindow{ nullptr };
        int thisWidth{ 0 };
        int thisHeight{ 0 };
    };
}