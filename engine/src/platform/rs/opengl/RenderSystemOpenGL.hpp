#pragma once

#include <GLFW/glfw3.h>
#include "core/RenderSystem.hpp"
#include <glad/>
namespace pd {
	class RenderSystemOpenGL : public RenderSystem {
	public:
        std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) override;
        void bindPipeline(const PipelineDesc& pipelineDesc) override;
        void draw(PipelineDesc state) override;
	};
}
