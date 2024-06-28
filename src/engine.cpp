#include "engine/engine.hpp"

namespace engine {
    void Init(const std::vector<const char*>& extensions, CreateSurfaceFunc func, int w, int h) {
        Context::Init(extensions, func);
        Context::GetInstance().InitSwapchain(w, h);
        Shader::Init(ReadWholeFile("./shaders/vert.spv"), ReadWholeFile("./shaders/frag.spv"));
        Context::GetInstance().renderProcess->InitRenderPass();
        Context::GetInstance().renderProcess->InitLayout();
        Context::GetInstance().swapchain->CreateFramebuffers(w, h);
        Context::GetInstance().renderProcess->InitPipeline(w, h);
        Context::GetInstance().InitRenderer();
    }

    void Quit() {
        //Context::GetInstance().logicDevice.waitIdle();
        Context::GetInstance().renderer.reset();
        Context::GetInstance().renderProcess.reset();
        Context::GetInstance().DestroySwapchain();
        Shader::Quit();
        Context::Quit();
    }
    
}