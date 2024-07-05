#pragma once
#include "vulkan/vulkan.hpp"
#include "context.hpp"
#include "command_manager.hpp"
#include "swapchain.hpp"
#include "vertex.hpp"
#include "buffer.hpp"
#include <limits>

namespace PrimalDawn {
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