#pragma once

#include <string>
#include <memory>

#include "platform/PlatformEnums.h"
#include "core/SwapChain.h"

namespace pd {
    class WindowSystem;

    struct PlatformConfig {
        Backend backend = Backend::VULKAN;
        std::string appName{"default"};
        std::string engineName{"Primal Dawn"};
        bool enableDebug = false;
    };
    /**
    * Platform封装了底层API和操作系统，包含各种通用操作
    */
    class Platform {
    public:

        Platform() noexcept = default;

        Platform(PlatformConfig& config) :
            mPlatformConfig(config) {
        }

        /**
        * @brief 为指定平台创建交换链
        */
        virtual std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) = 0;

        virtual ~Platform() noexcept = default;
    protected:
        PlatformConfig mPlatformConfig;
    };
}
