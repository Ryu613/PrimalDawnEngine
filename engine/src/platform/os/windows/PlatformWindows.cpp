#include <vector>
#include "platform/os/windows/PlatformWindows.hpp"
#include "platform/RenderSystemFactory.hpp"
#include "core/RenderSystem.hpp"
#include "core/Logging.hpp"

namespace pd {

    PlatformWindows::PlatformWindows(PlatformConfig& platformConfig)
        : Platform(platformConfig) {
        // 创建渲染系统
        LOG_INFO("Platform is creating render system...")
        RenderSystemConfig rsConfig;
        rsConfig.appName = platformConfig.appName;
        rsConfig.enableDebug = platformConfig.enableDebug;
        rsConfig.os = OS::WINDOWS;
        mRenderSystem = RenderSystemFactory::createRenderSystem(rsConfig);
    }

    //std::unique_ptr<SwapChain> PlatformVulkanWin32::createSwapChain(Engine& engine, WindowSystem* windowSystem) {
    //    // create surface
    //    void* nativeWindow = windowSystem->getNativeWindow();
    //    const vk::Win32SurfaceCreateInfoKHR surfaceCreateInfo({}, GetModuleHandle(nullptr), (HWND)nativeWindow, {});
    //    mSurface = mInstance.createWin32SurfaceKHR(surfaceCreateInfo);
    //    if (!mSurface) {
    //        throw std::runtime_error("faield to create window surface");
    //    }
    //    vk::Extent2D extent(windowSystem->getExtent().width, windowSystem->getExtent().hppeight);

    //    // create swapchain
    //    VulkanContext ctx(&mPhysicalDevice, &mDevice, &mSurface, &extent);
    //    return std::make_unique<PlatformVulkanSwapChain>(engine, &ctx);

    //}

}

