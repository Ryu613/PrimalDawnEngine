#pragma once
#include "vulkan/vulkan.hpp"

namespace engine {
    class RenderProcess final {
    public:
        vk::Pipeline pipeline;

        void InitPipeline(int width, int height);

        void DestroyPipeline();
    };
}