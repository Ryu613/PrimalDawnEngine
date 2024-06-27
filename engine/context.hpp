#pragma once

#include "vulkan/vulkan.hpp"
#include <memory>
#include <optional>

#include "tool.hpp"
#include "swapchain.hpp"
#include "render_process.hpp"
/*
    上下文（单例）
*/
namespace engine {
    class Context final {
    public:
        static void Init(const std::vector<const char*>& extensions, CreateSurfaceFunc func);
        static void Quit();
        static Context& GetInstance();
        ~Context();
        struct QueueFamilyIndices final {
            std::optional<uint32_t> graphicsQueue;
            std::optional<uint32_t> presentQueue;

            operator bool() const {
                return graphicsQueue.has_value() && presentQueue.has_value();
            }
        };
        vk::Instance instance;
        vk::PhysicalDevice physicalDevice;
        vk::Device logicDevice;
        // 图像队列(逻辑设备使用)
        vk::Queue graphicsQueue;
        vk::Queue presentQueue;
        // surface:用于处理从GPU获取的图片转换到屏幕对应的格式
        vk::SurfaceKHR surface;
        std::unique_ptr<Swapchain> swapchain;
        std::unique_ptr<RenderProcess> renderProcess;
        // 逻辑设备队列的索引
        QueueFamilyIndices queueFamilyIndices;

        void InitSwapchain(int w, int h) {
            swapchain.reset(new Swapchain(w, h));
        }

        void DestroySwapchain() {
            swapchain.reset();
        }
    private:
        Context(const std::vector<const char*>& extensions, CreateSurfaceFunc func);

        static std::unique_ptr<Context> instance_;

        void createInstance(const std::vector<const char*>& extensions);

        void pickupPhysicalDevice();
         
        void createLogicDevice();

        void getQueues();

        void queryQueueFamilyIndices();
};
}