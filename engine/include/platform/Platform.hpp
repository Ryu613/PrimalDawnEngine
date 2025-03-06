#pragma once

#include <string>
#include <memory>

#include "platform/PlatformEnums.hpp"
#include "core/SwapChain.hpp"

namespace pd {
    class GraphicsCore;

    struct PlatformConfig {
        Backend backend = Backend::VULKAN;
        std::string appName{"default"};
        std::string engineName{"Primal Dawn"};
        bool enableDebug = false;
    };
    /**
    * 平台层总抽象，定义平台通用操作，派生类根据对应平台进行操作扩展
    */
    class Platform {
    public:
        Platform(const PlatformConfig& config)
            : mPlatformConfig(config) {
        }

        virtual ~Platform() noexcept = default;
    
    protected:
        PlatformConfig mPlatformConfig;
        GraphicsCore* mGraphicsCore{nullptr};
    };
}
