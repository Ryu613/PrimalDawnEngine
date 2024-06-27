#include "engine/engine.hpp"

namespace engine {
    void Init(const std::vector<const char*>& extensions, CreateSurfaceFunc func, int w, int h) {
        Context::Init(extensions, func);
        Context::GetInstance().InitSwapchain(w, h);
        Shader::Init(ReadWholeFile("./shaders/vert.spv"), ReadWholeFile("./shaders/frag.spv"));
        Context::GetInstance().renderProcess->InitPipeline(w, h);
    }

    void Quit() {
        Context::GetInstance().renderProcess->DestroyPipeline();
        Context::GetInstance().DestroySwapchain();
        Shader::Quit();
        Context::Quit();
    }
    
}