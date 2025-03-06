#include "platform/PlatformFactory.hpp"

#if defined(WIN32)
#include "platform/os/windows/PlatformWindows.hpp"
#endif

namespace pd {
    std::unique_ptr<Platform> PlatformFactory::createPlatform(OS os) {
    #if defined(WIN32)
        LOG_INFO("Platform is {}", "Windows")
        return std::make_unique<PlatformWindows>(PlatformConfig);
    #else
        LOG_INFO("Platform is {}", "Vulkan - Unknown OS")
        return nullptr;
    #endif
    }

}
