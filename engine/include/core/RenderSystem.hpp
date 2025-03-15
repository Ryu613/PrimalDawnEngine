#pragma once

#include <string>
#include <memory>
#include "platform/PlatformEnums.hpp"

namespace pd {
    class Engine;
    class WindowSystem;
    class SwapChain;

    struct RenderSystemConfig {
        std::string appName{"default"};
        std::string engineName{ "Primal Dawn" };
        OS os = OS::UNKNOWN;
        Backend backend = Backend::UNKWONN;
        bool enableDebug = false;
    };
    /**
    * @brief 渲染系统接口，不同图形API的总类
    */
    class RenderSystem {
    public:
        /**
        * @brief 为指定平台创建交换链
        */
        virtual std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) = 0;
    protected:
        RenderSystem(RenderSystemConfig& cfg);
        RenderSystemConfig& mRenderSystemConfig;
    private:
    };
}
