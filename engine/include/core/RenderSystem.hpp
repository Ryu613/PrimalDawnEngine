#pragma once

#include <string>
#include "platform/PlatformEnums.hpp"

namespace pd {
    class Engine;
    class WindowSystem;
    class Swapchain;

    struct RenderSystemConfig {
        std::string appName{"default"};
        OS os = OS::UNKNOWN;
        Backend backend = Backend::UNKWONN;
        bool enableDebug = false;
    };
    /**
    * @brief 渲染系统，不同图形API的总类
    */
    class RenderSystem {
    public:
        /**
        * @brief 为指定平台创建交换链
        */
        //Swapchain* createSwapChain(Engine& engine, WindowSystem* windowSystem);

    };
}
