#pragma once

#include <memory>
#include "platform/Platform.hpp"
#include "core/RenderSystem.hpp"

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
        PlatformWindows(PlatformConfig& platformConfig);
        ~PlatformWindows() = default;
    private:
        /**
        * 创建渲染系统
        */
        void createRenderSystem();
    };
}
