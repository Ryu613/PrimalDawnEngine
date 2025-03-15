#pragma once

#include "VulkanCommon.hpp"

namespace pd {
    class VulkanContext {
        friend class RenderSystemVulkan;
        friend class VulkanSwapChain;
    public:

        MOVABLE_ONLY(VulkanContext);

        VulkanContext() = default;

        vk::ShaderModule createShaderModule(const char* filepath);
    private:
        vk::Instance mInstance = nullptr;
        vk::PhysicalDevice mPhysicalDevice = nullptr;
        vk::Device mDevice = nullptr;
        VmaAllocator mVmaAllocator = nullptr;
        vk::SurfaceKHR mSurface = nullptr;
        vk::Extent2D mExtent2D;

        vk::DebugUtilsMessengerEXT mDebugUtilsMsgr;

        uint32_t mGraphicsQueueIndex = INVALID_VK_INDEX;
        vk::Queue mGraphicsQueue = VK_NULL_HANDLE;

    };
}
