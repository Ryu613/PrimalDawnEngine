#pragma once
#include "platform/Platform.h"
#include "VulkanCommon.h"
#include "core/SwapChain.h"

namespace pd {

    class PlatformVulkanWin32 : public Platform {
    public:
        PlatformVulkanWin32(PlatformConfig &platformConfig);
        ~PlatformVulkanWin32();
        std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) override;
    private:
        vk::Instance mInstance = VK_NULL_HANDLE;
        vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        unsigned int mGraphicsQueueIndex = 0;
        vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
        vk::Device mDevice = VK_NULL_HANDLE;
        vk::Queue mGraphicsQueue = VK_NULL_HANDLE;
    };

    bool validateExtensions(const std::vector<const char*>& required,
        const std::vector<vk::ExtensionProperties>& available);
}
