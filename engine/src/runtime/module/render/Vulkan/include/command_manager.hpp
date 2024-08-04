#pragma once

#include "vulkan/vulkan.hpp"

namespace PrimalDawn {

    class CommandManager final {
    public:
        CommandManager();
        ~CommandManager();

        vk::CommandBuffer CreateOneCommandBuffer();
        std::vector<vk::CommandBuffer> CreateCommandBuffers(std::uint32_t count);
        void ResetCmds();
        void FreeCmd(vk::CommandBuffer);

    private:
        vk::CommandPool pool_;

        vk::CommandPool createCommandPool();
    };

}