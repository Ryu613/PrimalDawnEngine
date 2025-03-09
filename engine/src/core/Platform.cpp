#include "platform/Platform.hpp"

namespace pd {

    Platform::Platform(PlatformConfig& platformConfig)
        : mPlatformConfig(platformConfig) {
    }

    PlatformConfig Platform::getPlatformConfig() const {
        return mPlatformConfig;
    }

    RenderSystem* Platform::getRenderSystem() const {
        return mRenderSystem.get();
    }
}
