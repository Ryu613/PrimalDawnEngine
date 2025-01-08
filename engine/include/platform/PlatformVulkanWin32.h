#pragma once
#define VK_USE_PLATFORM_WIN32_KHR 1
#include <vulkan/vulkan.hpp>
#include "platform/Platform.h"

namespace pd {

    class PlatformVulkanWin32 : public Platform {
    public:
        PlatformVulkanWin32(PlatformConfig &platformConfig);
        ~PlatformVulkanWin32();
    private:
        vk::Instance mInstance = VK_NULL_HANDLE;
        vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        unsigned int mGraphicsQueueIndex = 0;
        vk::Device mDevice = VK_NULL_HANDLE;
        vk::Queue mGraphicsQueue = VK_NULL_HANDLE;
    };

    bool validateExtensions(const std::vector<const char*>& required,
        const std::vector<vk::ExtensionProperties>& available);
}
