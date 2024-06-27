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
        // Ҫ������layers
        std::vector<const char*> layers = { "VK_LAYER_KHRONOS_validation" };
        // ����vkʵ���Ĳ����ʹ���ʵ��
        vk::InstanceCreateInfo createInfo;
        vk::ApplicationInfo appInfo;
        // ָ��vk�汾��
        appInfo.setApiVersion(VK_API_VERSION_1_3);

        RemoveNosupportedElems<const char*, vk::LayerProperties>(layers, vk::enumerateInstanceLayerProperties(),
            [](const char* e1, const vk::LayerProperties& e2) {
                return std::strcmp(e1, e2.layerName) == 0;
            });

        // ����createInfo
        createInfo.setPApplicationInfo(&appInfo)
            .setPEnabledLayerNames(layers)
            .setPEnabledExtensionNames(extensions);
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
        std::array extensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
        vk::DeviceCreateInfo createInfo;
        std::vector<vk::DeviceQueueCreateInfo> queueCreateInfos;
        float priorities = 1.0;
        if (queueFamilyIndices.presentQueue.value() == queueFamilyIndices.graphicsQueue.value()) {
            vk::DeviceQueueCreateInfo queueCreateInfo;
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // ��ѯָ�����
                .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
            // Queue��ָ��ָ����У����ڰ��߼��豸��ָ��(ͨ��CommandBuffer(ָ���))���������豸
            queueCreateInfos.push_back(std::move(queueCreateInfo));
        }
        else {
            vk::DeviceQueueCreateInfo queueCreateInfo;
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // ��ѯָ�����
                .setQueueFamilyIndex(queueFamilyIndices.graphicsQueue.value());
            // Queue��ָ��ָ����У����ڰ��߼��豸��ָ��(ͨ��CommandBuffer(ָ���))���������豸
            queueCreateInfos.push_back(queueCreateInfo);
            queueCreateInfo.setPQueuePriorities(&priorities)
                .setQueueCount(1)
                // ��ѯָ�����
                .setQueueFamilyIndex(queueFamilyIndices.presentQueue.value());
            queueCreateInfos.push_back(queueCreateInfo);
        }
        // Queue��ָ��ָ����У����ڰ��߼��豸��ָ��(ͨ��CommandBuffer(ָ���))���������豸
        createInfo.setQueueCreateInfos(queueCreateInfos)
            .setPEnabledExtensionNames(extensions);
        logicDevice = physicalDevice.createDevice(createInfo);
    }

    void Context::queryQueueFamilyIndices() {
        auto properties = physicalDevice.getQueueFamilyProperties();
        for (int i = 0; i < properties.size(); i++) {
            const auto& property = properties[i];
            // �ҵ�
            if (property.queueFlags & vk::QueueFlagBits::eGraphics) {
                queueFamilyIndices.graphicsQueue = i;
            }
            // ����������Ƿ�֧��surface��ʾ
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