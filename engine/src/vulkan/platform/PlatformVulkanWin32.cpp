#include <vector>
#include "platform/PlatformVulkanWin32.h"
#include "platformVulkanSwapChain.h"
#include "platform/WindowSystem.h"
#include "VulkanContext.h"
#include "core/util/Logging.h"

using namespace pd;

PlatformVulkanWin32::PlatformVulkanWin32(PlatformConfig& platformConfig) :
    Platform(platformConfig) {
    // create instance
    std::vector<vk::ExtensionProperties> availableInstanceextensions = vk::enumerateInstanceExtensionProperties();
    std::vector<const char*> activeInstanceExtensions({ VK_KHR_SURFACE_EXTENSION_NAME });
    if (mPlatformConfig.enableDebug) {
        activeInstanceExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }
    activeInstanceExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
    if (!validateExtensions(activeInstanceExtensions, availableInstanceextensions)) {
        throw std::runtime_error("Required instance extensions are missing");
    }
    vk::ApplicationInfo app(mPlatformConfig.appName.c_str(), {}, mPlatformConfig.engineName.c_str(), {}, VK_MAKE_VERSION(1, 0, 0));
    vk::InstanceCreateInfo instanceInfo({}, &app, {}, activeInstanceExtensions);
    // instance create
    mInstance = vk::createInstance(instanceInfo);
    // select physical device
    std::vector<vk::PhysicalDevice> gpus = mInstance.enumeratePhysicalDevices();
    bool foundGraphicsQueueIndex = false;
    for (auto i = 0; i < gpus.size() && !foundGraphicsQueueIndex; ++i) {
        mPhysicalDevice = gpus[i];
        std::vector<vk::QueueFamilyProperties> queueFamilyProperties = mPhysicalDevice.getQueueFamilyProperties();
        if (queueFamilyProperties.empty()) {
            throw std::runtime_error("no queue family found");
        }
        // TODO 做设备扩展验证
    }
    // create device
    std::vector<vk::ExtensionProperties> deviceExtensions = mPhysicalDevice.enumerateDeviceExtensionProperties();
    std::vector<const char*> requiredDeviceExtensions({ VK_KHR_SWAPCHAIN_EXTENSION_NAME });
    if (!validateExtensions(requiredDeviceExtensions, deviceExtensions)) {
        throw std::runtime_error("Required device extensions are missing!");
    }
    float queuePriority = 1.f;
    vk::DeviceQueueCreateInfo queueInfo({}, mGraphicsQueueIndex, 1, &queuePriority);
    vk::DeviceCreateInfo deviceInfo({}, queueInfo, {}, requiredDeviceExtensions);
    // device create
    mDevice = mPhysicalDevice.createDevice(deviceInfo);
    mGraphicsQueue = mDevice.getQueue(mGraphicsQueueIndex, 0);
}

PlatformVulkanWin32::~PlatformVulkanWin32() {

}

std::unique_ptr<SwapChain> PlatformVulkanWin32::createSwapChain(WindowSystem* windowSystem) {
    // create surface
    void* nativeWindow = windowSystem->getNativeWindow();
    const vk::Win32SurfaceCreateInfoKHR surfaceCreateInfo({}, GetModuleHandle(nullptr), (HWND)nativeWindow, {});
    mSurface = mInstance.createWin32SurfaceKHR(surfaceCreateInfo);
    vk::Extent2D extent(windowSystem->getExtent().width, windowSystem->getExtent().height);
    // create swapchain
    VulkanContext ctx(&mPhysicalDevice, &mDevice, &mSurface, &extent);
    return std::make_unique<PlatformVulkanSwapChain>(&ctx);
    
}

bool pd::validateExtensions(const std::vector<const char*>& required,
    const std::vector<vk::ExtensionProperties>& available) {
    return std::find_if(required.begin(),
        required.end(),
        [&available](auto extension) {
            return std::find_if(available.begin(),
                available.end(),
                [&extension](auto const& ep) {
                    return strcmp(ep.extensionName, extension) == 0;
                }) == available.end();
        }) == required.end();
}

