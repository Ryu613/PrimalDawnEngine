#include "platform/PlatformFactory.h"
#include "core/util/Logging.h"

#if defined(WIN32)
#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/PlatformVulkanWin32.h"
#endif
#endif

using namespace pd;

std::unique_ptr<Platform> PlatformFactory::create(PlatformConfig &PlatformConfig) noexcept {
    if (PlatformConfig.backend == Backend::VULKAN) {
#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
    #if defined(WIN32)
        LOG_INFO("Platform is {}", "Vulkan - Win32")
        return std::make_unique<PlatformVulkanWin32>(PlatformConfig);
    #else
        LOG_INFO("Platform is {}", "Vulkan - Unknown OS")
        return nullptr;
    #endif
#else
        LOG_INFO("Platform is {}", "Unknown Graphic API - Unknown OS")
        return nullptr;
#endif
    }
}

