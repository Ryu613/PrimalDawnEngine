#include "platform/Platform.hpp"
#include "core/RenderSystemFactory.hpp"

namespace pd {

    Platform::Platform(PlatformConfig& platformConfig)
        : mPlatformConfig(platformConfig) {
        init();
    }

    /**
    * 根据Backend类型创建渲染系统
    */
    void Platform::init() {
        createRenderSystem();
    }

    void Platform::createRenderSystem() {
        RenderSystemConfig rsConfig;
        rsConfig.enableDebug = mPlatformConfig.enableDebug;
        mRenderSystem = RenderSystem::create(rsConfig);
    }
}
