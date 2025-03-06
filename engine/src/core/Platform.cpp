#include "platform/Platform.hpp"

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
    }
}
