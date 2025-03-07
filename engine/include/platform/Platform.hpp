#pragma once

#include <string>
#include "platform/PlatformEnums.hpp"

namespace pd {

    struct PlatformConfig {
        std::string appName{ "default" };
        Backend backend = Backend::VULKAN;
        bool enableDebug = false;
    };
    /**
    * 平台层总抽象，定义平台通用操作，派生类根据对应平台进行操作扩展
    */
    class Platform {
    public:

        Platform(PlatformConfig& platformConfig);
        ~Platform() noexcept = default;
        /**
        * 获取平台配置项
        */
        PlatformConfig getPlatformConfig() const;

    protected:

    private:
        PlatformConfig& mPlatformConfig;
    };
}
