#include "platform/PlatformFactory.h"

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
        return std::make_unique<PlatformVulkanWin32>(PlatformConfig);
    #else
        return nullptr;
    #endif
#else
        return nullptr;
#endif
    }
}

