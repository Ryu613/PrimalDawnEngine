#include "engine/context.hpp"
#include <iostream>

namespace engine {

    std::unique_ptr<Context> Context::instance_ = nullptr;

    void Context::Init(const std::vector<const char*>& extensions, CreateSurfaceFunc func) {
        instance_.reset(new Context(extensions, func));

    }
    void Context::Quit() {
        instance_.reset();
    }
    Context& Context::GetInstance() {
        return *instance_;
    }

    Context::Context(const std::vector<const char*>& extensions, CreateSurfaceFunc func) {
        createInstance(extensions);
        pickupPhysicalDevice();
        surface = func(instance);
        queryQueueFamilyIndices();
        createLogicDevice();
        getQueues();
        renderProcess.reset(new RenderProcess);
    }

    Context::~Context() {
        instance.destroySurfaceKHR(surface);
        logicDevice.destroy();
        instance.destroy();
    }

    void Context::createInstance(const std::vector<const char*>& extensions) {
        // 要开启的layers
        std::vector<const char*> layers = { "VK_LAYER_KHRONOS_validation" };
        // 配置vk实例的参数和创建实例
        vk::InstanceCreateInfo createInfo;
        vk::ApplicationInfo appInfo;
        // 指定vk版本号
        appInfo.setApiVersion(VK_API_VERSION_1_3);

        RemoveNosupportedElems<const char*, vk::LayerProperties>(layers, vk::enumerateInstanceLayerProperties(),
            [](const char* e1, const vk::LayerProperties& e2) {
                return std::strcmp(e1, e2.layerName) == 0;
            });

        // 配置createInfo
        createInfo.setPApplicationInfo(&appInfo)
            .setPEnabledLayerNames(layers)
            .setPEnabledExtensionNames(extensions);
        // 创建vulkan实例
        instance = vk::createInstance(createInfo);
    }

    void Context::pickupPhysicalDevice() {
        // 列举所有物理设备
        auto devices = instance.enumeratePhysicalDevices();
        // 自信选择第一个物理设备
        physicalDevice = devices[0];
        /*for (auto& device : devices) {
            auto feature = device.getFeatures();
            if(feature.geometryShader)
        }*/
        std::cout << "physical device name: " << physicalDevice.getProperties().deviceName << std::endl;
    }

    void Context::createLogicDevice() {
        std::array extensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
        vk::DeviceCreateInfo createInfo;
        std::vector<vk::DeviceQueueCreateInfo> queueCreateInfos;
        float priorities = 1.0;
        if (queueFamilyIndices.presentQueue.value() == queueFamilyIndices.graphicsQueue.value()) {
            vk::DeviceQueueCreateInfo queueCreateInfo;
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // 查询指令队列
                .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
            // Queue：指定指令队列，用于把逻辑设备的指令(通过CommandBuffer(指令缓冲))传给物理设备
            queueCreateInfos.push_back(std::move(queueCreateInfo));
        }
        else {
            vk::DeviceQueueCreateInfo queueCreateInfo;
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // 查询指令队列
                .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
            // Queue：指定指令队列，用于把逻辑设备的指令(通过CommandBuffer(指令缓冲))传给物理设备
            queueCreateInfos.push_back(queueCreateInfo);
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // 查询指令队列
                .setQueueFamilyIndex(queueFamilyIndices.presentQueue.value());
            queueCreateInfos.push_back(queueCreateInfo);
        }
        // Queue：指定指令队列，用于把逻辑设备的指令(通过CommandBuffer(指令缓冲))传给物理设备
        createInfo.setQueueCreateInfos(queueCreateInfos)
            .setPEnabledExtensionNames(extensions);
        logicDevice = physicalDevice.createDevice(createInfo);
    }

    void Context::queryQueueFamilyIndices() {
        auto properties = physicalDevice.getQueueFamilyProperties();
        for (int i = 0; i < properties.size(); i++) {
            const auto& property = properties[i];
            // 找到
            if (property.queueFlags & vk::QueueFlagBits::eGraphics) {
                queueFamilyIndices.graphicsQueue = i;
            }
            // 看命令队列是否支持surface显示
            if (physicalDevice.getSurfaceSupportKHR(i, surface)) {
                queueFamilyIndices.presentQueue = i;
            }
            if (queueFamilyIndices) {
                break;
            }
        }
    }

    void Context::getQueues() {
        graphicsQueue = logicDevice.getQueue(queueFamilyIndices.graphicsQueue.value(), 0);
        presentQueue = logicDevice.getQueue(queueFamilyIndices.presentQueue.value(), 0);
    }
}