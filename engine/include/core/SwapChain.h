#pragma once

namespace pd {
    class Engine;
    /**
    * @brief 这里的swapchain为不同操作系统的原生渲染界面的操作提供统一封装的抽象
    */
    class SwapChain {
    public:
        SwapChain(Engine& engine);
        virtual ~SwapChain() = default;
    private:
        Engine& mEngine;
        unsigned int mWidth = 0;
        unsigned int mHeight = 0;
    };
}
