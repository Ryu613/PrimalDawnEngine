#pragma once

#include "vulkan/vulkan.hpp"
#include <memory>
#include <optional>
/*
    上下文（单例）
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
        // 图像队列(逻辑设备使用)
        vk::Queue graphicsQueue;
        // 逻辑设备队列的索引
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