#pragma once

#include "platform/Platform.hpp"

namespace pd {
    struct RenderSystemConfig;
    class RenderSystem;

    /**
    * 负责windows平台的相关事务，包括:
    * 1. 具体渲染系统的管理
    */
    class PlatformWindows : public Platform {
    friend class PlatformFactory;
    public:
    private:
        PlatformWindows(PlatformConfig& platformConfig);
        ~PlatformWindows();

        /**
        * @brief 初始化平台层里面的各种系统，包括渲染系统等
        */
        void init();

        /**
        * 创建渲染系统
        */
        void createRenderSystem();

        std::unique_ptr<RenderSystem> mRenderSystem{nullptr};
    };

    //bool validateExtensions(const std::vector<const char*>& required,
    //    const std::vector<vk::ExtensionProperties>& available);
}
