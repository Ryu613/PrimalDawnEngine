#include "impl/factory.hpp"

#include <memory>

#include "primaldawn/platform.hpp"
#include "primaldawn/config.hpp"
#if defined(WIN32)
#include "platform/os/platform_windows.hpp"
#endif

#include "logging.hpp"

namespace primaldawn::factory {

    std::unique_ptr<Platform> CreatePlatform(config::Platform config) {
    #if defined(WIN32)
        LOGI("Platform is {}", "Windows")
        return std::make_unique<PlatformWindows>(std::move(config));
    #else
        LOG_INFO("Platform is {}", "Vulkan - Unknown OS")
        return nullptr;
    #endif
    }

} // namespace primaldawn::factory
