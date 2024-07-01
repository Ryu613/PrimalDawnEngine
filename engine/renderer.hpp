#pragma once
#include "vulkan/vulkan.hpp"
#include "engine/context.hpp"
#include "engine/command_manager.hpp"
#include "engine/swapchain.hpp"
#include "engine/vertex.hpp"
#include "engine/buffer.hpp"
#include <limits>

namespace engine {
    class Renderer final {
    public:
        Renderer(int maxFlightCount = 2);
        ~Renderer();

        void DrawTriangle();
    private:
        int maxFlightCount_;
        int curFrame_;
        std::vector<vk::Fence> fences_;
        std::vector<vk::Semaphore> imageAvaliableSems_;
        std::vector<vk::Semaphore> renderFinishSems_;
        std::vector<vk::CommandBuffer> cmdBufs_;

        std::unique_ptr<Buffer> hostVertexBuffer_;
        std::unique_ptr<Buffer> deviceVertexBuffer_;

        void createFences();
        void createSemaphores();
        void createCmdBuffers();
        void createVertexBuffer();
        void bufferVertexData();
    };
}