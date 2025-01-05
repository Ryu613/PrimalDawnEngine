#pragma once

#include "platform/Platform.h"

namespace pd {
    class PlatformVulkan : public Platform {
    public:
        PlatformVulkan() = default;
        ~PlatformVulkan() override = default;
        virtual Driver* createDriver() noexcept override;
    private:
        // Luma Vulkan类封装
    };
}
