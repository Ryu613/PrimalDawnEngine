#include "platform/render_system/vulkan/vulkan_context.hpp"

#include <vector>
#include <stdexcept>

#include "primaldawn/logging.hpp"

VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE

namespace primaldawn {

    VKAPI_ATTR VkBool32 VKAPI_CALL DebugUtilsCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
        VkDebugUtilsMessageTypeFlagsEXT message_type,
        const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
        void* user_data) {
        if (message_severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
            LOGW("{} - {}: {}", callback_data->messageIdNumber, callback_data->pMessageIdName, callback_data->pMessage);
        }
        else if (message_severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
            LOGE("{} - {}: {}", callback_data->messageIdNumber, callback_data->pMessageIdName, callback_data->pMessage);
        }
        return VK_FALSE;
    }

    VKAPI_ATTR VkBool32 VKAPI_CALL DebugReportCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT /*type*/,
        uint64_t /*object*/, size_t /*location*/, int32_t /*message_code*/,
        const char* layer_prefix, const char* message, void* /*user_data*/) {
        if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) {
            LOGE("{}: {}", layer_prefix, message);
        }
        else if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT) {
            LOGW("{}: {}", layer_prefix, message);
        }
        else if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) {
            LOGW("{}: {}", layer_prefix, message);
        }
        else {
            LOGI("{}: {}", layer_prefix, message);
        }
        return VK_FALSE;
    }

    VulkanContext::VulkanContext(VulkanConfig cfg)
      : vulkan_config_(std::move(cfg)) {
        LOGI("initializing Vulkan...")
        static vk::DynamicLoader dl;
        VULKAN_HPP_DEFAULT_DISPATCHER.init(dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr"));
        std::vector<vk::ExtensionProperties> available_instance_extensions = vk::enumerateInstanceExtensionProperties();
        std::vector<const char*> active_instance_extensions({ VK_KHR_SURFACE_EXTENSION_NAME });
        std::vector<const char*> active_instance_layers;
        if (vulkan_config_.enable_debug) {
            if (HasExtensions(VK_EXT_DEBUG_UTILS_EXTENSION_NAME, available_instance_extensions)) {
                vulkan_config_.use_debug_utils = true;
                active_instance_extensions.emplace_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            }
            else if (HasExtensions(VK_EXT_DEBUG_REPORT_EXTENSION_NAME, available_instance_extensions)) {
                vulkan_config_.use_debug_report = true;
                active_instance_extensions.emplace_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
            }
            else {
                LOGW("vulkan debug utils/debug report not supported! use validation layers")
                vulkan_config_.use_debug_utils = false;
                vulkan_config_.use_debug_report = false;
            }
            active_instance_layers.emplace_back("VK_LAYER_KHRONOS_validation");
        }
        if (vulkan_config_.os == OS::WINDOWS) {
            active_instance_extensions.emplace_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
        }
        else {
            throw std::runtime_error("Unknown OS not supported !");
        }
        if (!ValidateExtensions(active_instance_extensions, available_instance_extensions)) {
            throw std::runtime_error("Required instance extensions are missing");
        }
        vk::ApplicationInfo app_info(vulkan_config_.app_name.c_str(), {}, vulkan_config_.engine_name.c_str(), {}, VK_MAKE_VERSION(1, 0, 0));
        vk::InstanceCreateInfo instance_info({}, &app_info, active_instance_layers, active_instance_extensions);
        if (vulkan_config_.enable_debug) {
            if (vulkan_config_.use_debug_utils) {
                vk::DebugUtilsMessengerCreateInfoEXT debug_utils_create_info =
                    vk::DebugUtilsMessengerCreateInfoEXT({},
                        vk::DebugUtilsMessageSeverityFlagBitsEXT::eError | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning,
                        vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance,
                        DebugUtilsCallback);
                instance_info.pNext = &debug_utils_create_info;
            }
            else if (vulkan_config_.use_debug_report) {
                vk::DebugReportCallbackCreateInfoEXT debug_report_create_info =
                    vk::DebugReportCallbackCreateInfoEXT(
                        vk::DebugReportFlagBitsEXT::eError | vk::DebugReportFlagBitsEXT::eWarning | vk::DebugReportFlagBitsEXT::ePerformanceWarning,
                        DebugReportCallback);
                instance_info.pNext = &debug_report_create_info;
            }
        }
        LOGI("creating Vulkan instance...")
        instance_ = vk::createInstance(instance_info);
        VULKAN_HPP_DEFAULT_DISPATCHER.init(instance_);
        // debug messenger
        if (vulkan_config_.enable_debug) {
           // mVulkanContext->mDebugUtilsMsgr = mVulkanContext->mInstance.createDebugUtilsMessengerEXT(debugUtilCreateInfo);
        }
        // select physical device
        std::vector<vk::PhysicalDevice> gpus = instance_.enumeratePhysicalDevices();
        std::vector<const char*> required_device_extensions({ VK_KHR_SWAPCHAIN_EXTENSION_NAME });
        if (vulkan_config_.enable_debug) {
            // TODO : add validation Layers
            // requiredDeviceExtensions.push_back(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
        }
        for (auto i = 0; i < gpus.size(); ++i) {
            physical_device_ = gpus[i];
            // check device extensions support
            std::vector<vk::ExtensionProperties> device_extensions = physical_device_.enumerateDeviceExtensionProperties();
            if (!ValidateExtensions(required_device_extensions, device_extensions)) {
                continue;
            }
            std::vector<vk::QueueFamilyProperties> queue_family_properties = physical_device_.getQueueFamilyProperties();
            if (queue_family_properties.empty()) {
                throw std::runtime_error("no queue family found");
            }
            for (uint32_t j = 0; j < queue_family_properties.size(); ++j) {
                vk::QueueFamilyProperties props = queue_family_properties[j];
                if (props.queueCount != 0 && (props.queueFlags & vk::QueueFlagBits::eGraphics)) {
                    graphics_queue_index_ = j;
                    break;
                }
            }
        }
        if (graphics_queue_index_ == INVALID_VK_INDEX) {
            LOGE("GPU not support necessary queue family props! Vulkan initial failed")
            throw std::runtime_error("failed to select available physical device");
        }
        // create logical device
        float queue_priority = 1.f;
        vk::DeviceQueueCreateInfo queue_info({}, graphics_queue_index_, 1, &queue_priority);
        vk::DeviceCreateInfo device_info({}, queue_info, {}, required_device_extensions);
        // device create
        LOGI("creating Vulkan logical device...")
        logic_device_ = physical_device_.createDevice(device_info);
        VULKAN_HPP_DEFAULT_DISPATCHER.init(logic_device_);
        graphics_queue_ = logic_device_.getQueue(graphics_queue_index_, 0);
    }
    VulkanContext::~VulkanContext() {

    }

    bool ValidateExtensions(
        const std::vector<const char*>& required,
        const std::vector<vk::ExtensionProperties>& available) {
        bool flag = false;
        for (const auto& each_required : required) {
            flag = false;
            for (const auto& each_available : available) {
                if (strcmp(each_required, each_available.extensionName) == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }

    bool HasExtensions(const char* required, const std::vector<vk::ExtensionProperties>& available) {
        for (const auto& each : available) {
            if (strcmp(required, each.extensionName) == 0) {
                return true;
            }
        }
        return false;
    }
} // namespace primaldawn
