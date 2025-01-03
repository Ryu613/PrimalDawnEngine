#ifndef DAWN_PRIMALDAWN_ENGINE_PLATFORMVULKAN_H
#define DAWN_PRIMALDAWN_ENGINE_PLATFORMVULKAN_H

#include "platform/Platform.h"

namespace pd {
    class PlatformVulkan : public Platform {
    public:
        PlatformVulkan() = default;
        ~PlatformVulkan() override = default;
        virtual Driver* createDriver() noexcept override;
    };
}

#endif
