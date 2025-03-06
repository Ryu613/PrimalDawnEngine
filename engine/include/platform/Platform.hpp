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
        * 根据操作系统和配置创建平台实例
        */
        static std::unique_ptr<Platform> create(PlatformConfig& platformConfig);

    protected:
        Platform(PlatformConfig& platformConfig);
        ~Platform() noexcept = default;

    private:
        /**
        * @brief 初始化平台层里面的各种系统，包括渲染系统等
        */
        void init();

        /**
        * 创建渲染系统
        */
        void createRenderSystem();

        PlatformConfig& mPlatformConfig;
        std::unique_ptr<RenderSystem> mRenderSystem{nullptr};
    };
}
