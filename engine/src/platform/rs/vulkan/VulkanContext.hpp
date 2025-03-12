#pragma once

#include "VulkanCommon.hpp"

namespace pd {
    class VulkanContext {
        friend class VulkanSwapChain;
        friend class VulkanShaderModule;
    public:
        VulkanContext(vk::PhysicalDevice* phyDevicePtr,
            vk::Device* devicePtr,
            vk::SurfaceKHR* surfacePtr,
            vk::Extent2D* extentPtr);
    private:
        vk::PhysicalDevice* mPhysicalDevice = nullptr;
        vk::Device* mDevice = nullptr;
        vk::SurfaceKHR* mSurface = nullptr;
        vk::Extent2D* mExtent2D = nullptr;

    };
}
