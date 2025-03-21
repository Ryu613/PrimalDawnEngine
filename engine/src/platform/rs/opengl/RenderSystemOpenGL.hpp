#pragma once

#include "core/RenderSystem.hpp"

namespace pd {
	class RenderSystemOpenGL : public RenderSystem {
	public:
        std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) override;
        void bindPipeline(const PipelineDesc& pipelineDesc) override;
        void draw(PipelineDesc state) override;
	};
}
