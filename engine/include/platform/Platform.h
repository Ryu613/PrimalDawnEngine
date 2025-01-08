#pragma once

#include <string>

#include "platform/PlatformEnums.h"

namespace pd {

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

        virtual ~Platform() noexcept = default;
    protected:
        PlatformConfig mPlatformConfig;
    };
}
