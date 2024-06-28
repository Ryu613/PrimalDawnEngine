#pragma once
#include "vulkan/vulkan.hpp"
#include "context.hpp"
#include "shader.hpp"

namespace engine {

    void Init(const std::vector<const char*>& extensions, CreateSurfaceFunc func, int w, int h);
    void Quit();
    inline Renderer& GetRenderer() {
        return *Context::GetInstance().renderer;
    }
}