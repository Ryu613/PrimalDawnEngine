#include <vector>
#include "platform/os/windows/PlatformWindows.hpp"
#include "platform/RenderSystemFactory.hpp"
#include "core/Logging.hpp"

namespace pd {

    PlatformWindows::PlatformWindows(PlatformConfig& platformConfig)
        : Platform(platformConfig) {
        // 创建渲染系统
        LOG_INFO("Platform is creating render system...")
        RenderSystemConfig rsConfig;
        rsConfig.appName = platformConfig.appName;
        rsConfig.enableDebug = platformConfig.enableDebug;
        rsConfig.os = OS::WINDOWS;
        mRenderSystem = RenderSystemFactory::createRenderSystem(rsConfig);
    }

}

