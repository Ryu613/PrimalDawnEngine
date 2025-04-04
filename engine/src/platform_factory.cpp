#include "tool/platform_factory.hpp"

#include "platform/platform_config.hpp"
#if defined(WIN32)
#include "platform/os/platform_windows.hpp"
#endif

#include "core/logging.hpp"

namespace primaldawn {
    std::unique_ptr<Platform> PlatformFactory::CreatePlatform(PlatformConfig config) {
    #if defined(WIN32)
        LOGI("Platform is {}", "Windows")
        return std::make_unique<PlatformWindows>(std::move(config));
    #else
        LOG_INFO("Platform is {}", "Vulkan - Unknown OS")
        return nullptr;
    #endif
    }

} // namespace primaldawn
