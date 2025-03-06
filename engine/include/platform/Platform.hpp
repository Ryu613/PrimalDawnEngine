#pragma once

#include <string>
#include <memory>
#include <stdexcept>

#include "platform/PlatformEnums.hpp"
#include "core/SwapChain.hpp"

namespace pd {
    class RenderSystem;

    struct PlatformConfig {
        Backend backend = Backend::VULKAN;
        bool enableDebug = false;
    };
    /**
    * 平台层总抽象，定义平台通用操作，派生类根据对应平台进行操作扩展
    */
    class Platform {
    public:
        /**
        * 获取平台配置项
        */
        PlatformConfig getPlatformConfig() const;

    private:

        Platform(PlatformConfig& platformConfig);
        ~Platform() noexcept = default;

        PlatformConfig& mPlatformConfig;
    };
}
