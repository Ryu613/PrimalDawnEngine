#pragma once

namespace pd {
    class SwapChain;
    class View;
    class Engine;
    /**
    * @brief 渲染器接口抽象，用于在窗口绘制图像，和相关操作的封装。一个窗口对应一个渲染器
    */
    class Renderer {
    public:

        Renderer(Engine& engine);

        ~Renderer() noexcept;

        Engine& getEngine() const noexcept {
            return mEngine;
        }

        /**
        * @brief 渲染某帧前的准备工作，并且检测本帧绘制耗时，若耗时长则可以跳过，反之则需要继续渲染
        * @return
        *   *true* 当前帧需要被绘制，且需调用endFrame()
        *   *false* 跳过当前帧
        */
        bool beginFrame(SwapChain* swapChain);

        /**
        * @brief 渲染整个场景
        */
        void render(const View* view);

        /**
        * 完成当前帧，并展示在渲染器对应的窗口上
        */
        void endFrame();
    private:
        Engine& mEngine;
        SwapChain* mSwapChain = nullptr;
    };
}
