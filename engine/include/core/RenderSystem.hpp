#pragma once

#include <string>
#include "platform/PlatformEnums.hpp"

namespace pd {
    class Engine;
    class WindowSystem;
    class SwapChain;

    struct RenderSystemConfig {
        std::string appName{"default"};
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
        virtual SwapChain* createSwapChain(Engine& engine, WindowSystem* windowSystem) = 0;

    };
}
