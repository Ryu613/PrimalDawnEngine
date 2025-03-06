#pragma once
#include "platform/Platform.hpp"
#include "VulkanCommon.hpp"
#include "core/SwapChain.hpp"

namespace pd {
    struct GraphicsCoreConfig;
    class GraphicsCore;

    class PlatformWindows final : public Platform {
    public:
        PlatformWindows(PlatformConfig &platformConfig);
        ~PlatformWindows();
    private:
        vk::Instance mInstance = VK_NULL_HANDLE;
        vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        uint32_t mGraphicsQueueIndex = 0xFFFFFFFF;
        vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
        vk::Device mDevice = VK_NULL_HANDLE;
        vk::Queue mGraphicsQueue = VK_NULL_HANDLE;

        void createGraphicsCore(GraphicsCoreConfig& gConfig);
    };

    bool validateExtensions(const std::vector<const char*>& required,
        const std::vector<vk::ExtensionProperties>& available);
}
