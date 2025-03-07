#include "platform/rs/vulkan/RenderSystemVulkan.hpp"
#include "core/Logging.hpp"

VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE

namespace pd {
    RenderSystemVulkan::RenderSystemVulkan(VulkanConfig& vulkanConfig)
        : mVulkanConfig(vulkanConfig) {
        initVulkanInstance();
    }

    void RenderSystemVulkan::initVulkanInstance() {
        LOG_INFO("initialize Vulkan Library")
            // init dynamic loader
            static vk::DynamicLoader dl;
        VULKAN_HPP_DEFAULT_DISPATCHER.init(dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr"));
        // create instance
        std::vector<vk::ExtensionProperties> availableInstanceextensions = vk::enumerateInstanceExtensionProperties();
        std::vector<const char*> activeInstanceExtensions({ VK_KHR_SURFACE_EXTENSION_NAME });
        if (mVulkanConfig.enableDebug) {
            activeInstanceExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            // more debug infos
            activeInstanceExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
        }
        activeInstanceExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
        if (!validateExtensions(activeInstanceExtensions, availableInstanceextensions)) {
            throw std::runtime_error("Required instance extensions are missing");
        }
        vk::ApplicationInfo app(mVulkanConfig.appName.c_str(), {}, mVulkanConfig.engineName.c_str(), {}, VK_MAKE_VERSION(1, 0, 0));
        vk::InstanceCreateInfo instanceInfo({}, &app, {}, activeInstanceExtensions);
        // instance create
        LOG_INFO("creating Vulkan instance...")
            mInstance = vk::createInstance(instanceInfo);
        if (!mInstance) {
            throw std::runtime_error("failed to create vulkan instance");
        }
        VULKAN_HPP_DEFAULT_DISPATCHER.init(mInstance);
        // select physical device
        std::vector<vk::PhysicalDevice> gpus = mInstance.enumeratePhysicalDevices();
        std::vector<const char*> requiredDeviceExtensions({ VK_KHR_SWAPCHAIN_EXTENSION_NAME });
        if (mVulkanConfig.enableDebug) {
            //requiredDeviceExtensions.push_back(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
        }
        for (auto i = 0; i < gpus.size(); ++i) {
            mPhysicalDevice = gpus[i];
            // check device extensions support
            std::vector<vk::ExtensionProperties> deviceExtensions = mPhysicalDevice.enumerateDeviceExtensionProperties();
            if (!validateExtensions(requiredDeviceExtensions, deviceExtensions)) {
                continue;
            }
            std::vector<vk::QueueFamilyProperties> queueFamilyProperties = mPhysicalDevice.getQueueFamilyProperties();
            if (queueFamilyProperties.empty()) {
                throw std::runtime_error("no queue family found");
            }
            for (uint32_t j = 0; j < queueFamilyProperties.size(); ++j) {
                vk::QueueFamilyProperties props = queueFamilyProperties[j];
                if (props.queueCount != 0 && (props.queueFlags & vk::QueueFlagBits::eGraphics)) {
                    mGraphicsQueueIndex = j;
                    break;
                }
            }
        }
        if (mGraphicsQueueIndex == INVALID_VK_INDEX) {
            LOG_ERROR("GPU not support necessary queue family props! Vulkan initial failed")
                throw std::runtime_error("failed to select available physical device");
        }
        // create logical device
        float queuePriority = 1.f;
        vk::DeviceQueueCreateInfo queueInfo({}, mGraphicsQueueIndex, 1, &queuePriority);
        vk::DeviceCreateInfo deviceInfo({}, queueInfo, {}, requiredDeviceExtensions);
        // device create
        LOG_INFO("creating Vulkan logical device...")
            mDevice = mPhysicalDevice.createDevice(deviceInfo);
        if (!mDevice) {
            throw std::runtime_error("failed to create vulkan device");
        }
        VULKAN_HPP_DEFAULT_DISPATCHER.init(mDevice);
        mGraphicsQueue = mDevice.getQueue(mGraphicsQueueIndex, 0);
        // TODO: create allocator
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
}
