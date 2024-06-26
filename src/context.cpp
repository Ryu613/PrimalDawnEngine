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
        // Ҫ������layers
        std::vector<const char*> layers = { "VK_LAYER_KHRONOS_validation" };
        // ����vkʵ���Ĳ����ʹ���ʵ��
        vk::InstanceCreateInfo createInfo;
        vk::ApplicationInfo appInfo;
        // ָ��vk�汾��
        appInfo.setApiVersion(VK_API_VERSION_1_3);

        // ����createInfo
        createInfo.setPApplicationInfo(&appInfo)
            .setPEnabledLayerNames(layers);
        // ����vulkanʵ��
        instance = vk::createInstance(createInfo);
    }

    void Context::pickupPhysicalDevice() {
        // �о����������豸
        auto devices = instance.enumeratePhysicalDevices();
        // ����ѡ���һ�������豸
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
            // ��ѯָ�����
            .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
        // Queue��ָ��ָ����У����ڰ��߼��豸��ָ��(ͨ��CommandBuffer(ָ���))���������豸
        createInfo.setQueueCreateInfos(queueCreateInfo);
        logicDevice = physicalDevice.createDevice(createInfo);
    }

    void Context::queryQueueFamilyIndices() {
        auto properties = physicalDevice.getQueueFamilyProperties();
        for (int i = 0; i < properties.size(); i++) {
            const auto& property = properties[i];
            // �ҵ�
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