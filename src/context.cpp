#include "engine/context.hpp"
#include <iostream>

namespace engine {

    std::unique_ptr<Context> Context::instance_ = nullptr;

    void Context::Init() {
        instance_.reset(new Context);

    }
    void Context::Quit() {
        instance_.reset();
    }
    Context& Context::GetInstance() {
        return *instance_;
    }

    Context::Context() {
        createInstance();
        pickupPhysicalDevice();
        queryQueueFamilyIndices();
        createLogicDevice();
        getQueues();
    }

    Context::~Context() {
        logicDevice.destroy();
        instance.destroy();
    }

    void Context::createInstance() {
        // 要开启的layers
        std::vector<const char*> layers = { "VK_LAYER_KHRONOS_validation" };
        // 配置vk实例的参数和创建实例
        vk::InstanceCreateInfo createInfo;
        vk::ApplicationInfo appInfo;
        // 指定vk版本号
        appInfo.setApiVersion(VK_API_VERSION_1_3);

        // 配置createInfo
        createInfo.setPApplicationInfo(&appInfo)
            .setPEnabledLayerNames(layers);
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
        vk::DeviceCreateInfo createInfo;
        vk::DeviceQueueCreateInfo queueCreateInfo;
        float priorities = 1.0;
        queueCreateInfo.setPQueuePriorities(&priorities)
            .setQueueCount(1)
            // 查询指令队列
            .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
        // Queue：指定指令队列，用于把逻辑设备的指令(通过CommandBuffer(指令缓冲))传给物理设备
        createInfo.setQueueCreateInfos(queueCreateInfo);
        logicDevice = physicalDevice.createDevice(createInfo);
    }

    void Context::queryQueueFamilyIndices() {
        auto properties = physicalDevice.getQueueFamilyProperties();
        for (int i = 0; i < properties.size(); i++) {
            const auto& property = properties[i];
            // 找到
            if (property.queueFlags & vk::QueueFlagBits::eGraphics) {
                queueFamilyIndices.graphicsQueue = i;
                break;
            }
        }
    }

    void Context::getQueues() {
        logicDevice.getQueue(queueFamilyIndices.graphicsQueue.value(), 0);
    }
}