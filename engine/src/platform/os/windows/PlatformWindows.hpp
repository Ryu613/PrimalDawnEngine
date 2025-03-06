#pragma once

#include "platform/Platform.hpp"

namespace pd {
    struct RenderSystemConfig;
    class RenderSystem;

    class PlatformWindows : public Platform {
    friend class PlatformFactory;
    public:
    private:
        PlatformWindows(PlatformConfig& platformConfig);
        ~PlatformWindows();
        std::unique_ptr<RenderSystem> mRenderSystem{nullptr};
        //vk::Instance mInstance = VK_NULL_HANDLE;
        //vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        //uint32_t mGraphicsQueueIndex = 0xFFFFFFFF;
        //vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
        //vk::Device mDevice = VK_NULL_HANDLE;
        //vk::Queue mGraphicsQueue = VK_NULL_HANDLE;

        //void createGraphicsCore(GraphicsCoreConfig& gConfig);
    };

    //bool validateExtensions(const std::vector<const char*>& required,
    //    const std::vector<vk::ExtensionProperties>& available);
}
