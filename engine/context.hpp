#pragma once

#include "vulkan/vulkan.hpp"
#include <memory>
#include <optional>
/*
    �����ģ�������
*/
namespace engine {
    class Context final {
    public:
        static void Init();
        static void Quit();
        static Context& GetInstance();
        ~Context();
        struct QueueFamilyIndices final {
            std::optional<uint32_t> graphicsQueue;
        };
        vk::Instance instance;
        vk::PhysicalDevice physicalDevice;
        vk::Device logicDevice;
        // ͼ�����(�߼��豸ʹ��)
        vk::Queue graphicsQueue;
        // �߼��豸���е�����
        QueueFamilyIndices queueFamilyIndices;
    private:
        Context();

        static std::unique_ptr<Context> instance_;

        void createInstance();

        void pickupPhysicalDevice();
         
        void createLogicDevice();

        void getQueues();

        void queryQueueFamilyIndices();
};
}