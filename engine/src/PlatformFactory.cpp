#include "platform/PlatformFactory.h"

#if defined(WIN32)
#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/PlatformVulkan.h"
#endif
#endif

using namespace pd;

std::unique_ptr<Platform> PlatformFactory::create(Backend* backend) {
    if (backend == Backend::VULKAN) {
#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
        return std::make_unique<PlatformVulkan>();
#else
        return nullptr;
#endif
    }
}

