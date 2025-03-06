#include "VulkanContext.hpp"

namespace pd {
    VulkanContext::VulkanContext(vk::PhysicalDevice* phyDevicePtr,
        vk::Device* devicePtr,
        vk::SurfaceKHR* surfacePtr,
        vk::Extent2D* extentPtr) :
        mPhysicalDevice(phyDevicePtr),
        mDevice(devicePtr),
        mSurface(surfacePtr),
        mExtent2D(extentPtr){}
}
