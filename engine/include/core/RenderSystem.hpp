#pragma once

#include <memory>

namespace pd {
    class Engine;
    class WindowSystem;
    class Swapchain;

    struct RenderSystemConfig {
        bool enableDebug = false;
    };
    /**
    * @brief 图形核心，底层图形API总接口
    */
    class RenderSystem {
    private:
        RenderSystem(RenderSystemConfig& gConfig);
        ~RenderSystem() noexcept = default;

        /**
        * @brief 为指定平台创建交换链
        */
        //Swapchain* createSwapChain(Engine& engine, WindowSystem* windowSystem);
        
    };
}
