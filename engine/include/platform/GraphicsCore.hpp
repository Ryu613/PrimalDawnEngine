#pragma once

namespace pd {
    class Engine;
    class WindowSystem;

    struct GraphicsCoreConfig {
        bool enableDebug = false;
    };
    /**
    * @brief 图形核心，底层图形API总接口
    */
    class GraphicsCore {
    public:
        GraphicsCore(const GraphicsCoreConfig& gConfig);
        virtual ~GraphicsCore() noexcept;

        /**
        * @brief 为指定平台创建交换链
        */
        virtual Swapchain* createSwapChain(Engine& engine, WindowSystem* windowSystem) = 0;
        

        
    };
}
