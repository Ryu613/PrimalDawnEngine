#pragma once

#include "GLCommon.hpp"
#include "core/RenderSystem.hpp"
#include "GLShader.hpp"
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
		GLShader mGLShader;
		unsigned int mTexture1;
		unsigned int mTexture2;
		unsigned int mVAO, mVBO, mEBO;
	};
}
