#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/RenderSystem.hpp"
namespace pd {
	class SwapChain;

	struct OpenGLConfig : public RenderSystemConfig {
	};
	class RenderSystemOpenGL : public RenderSystem {
	public:
		RenderSystemOpenGL(OpenGLConfig& config);
		~RenderSystemOpenGL();
        std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) override;
        void bindPipeline(const PipelineDesc& pipelineDesc) override;
        void draw(PipelineDesc state) override;
		void beginRenderPass() override;
		void endRenderPass() override;
	private:
		OpenGLConfig& mOpenGLConfig;
	};
}
