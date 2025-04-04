#include "RenderSystemOpenGL.hpp"
#include "core/SwapChain.hpp"

namespace pd {
    RenderSystemOpenGL::RenderSystemOpenGL(OpenGLConfig& config)
        : RenderSystem(config),
        mOpenGLConfig(config) {
    }

    RenderSystemOpenGL::~RenderSystemOpenGL() {
        //TODO destroy
    };

    std::unique_ptr<SwapChain> RenderSystemOpenGL::createSwapChain(Engine& engine, WindowSystem* windowSystem) {
        return nullptr;
    }
    void RenderSystemOpenGL::bindPipeline(const PipelineDesc& pipelineDesc) {
    }
    void RenderSystemOpenGL::draw(PipelineDesc desc) {

    }

    void RenderSystemOpenGL::beginRenderPass() {

    }
    void RenderSystemOpenGL::endRenderPass() {
    }
}
