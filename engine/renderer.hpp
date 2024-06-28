#pragma once
#include "vulkan/vulkan.hpp"
#include <iostream>

namespace engine {
    class Renderer final {
    public:
        Renderer();
        ~Renderer();

        void render();
    private:
        vk::CommandPool cmdPool_;
        vk::CommandBuffer cmdBuf_;
        vk::Semaphore imageAvailable_;
        vk::Semaphore imageDrawFinish_;
        vk::Fence cmdAvailableFence_;

        void initCmdPool();
        void allocCmdBuf();
        void createSems();
        void createFence();
    };
}