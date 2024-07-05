#pragma once
#include "context.hpp"
#include "render_process.hpp"
#include "renderer.hpp"
#include <memory>

namespace PrimalDawn {

    void Init(std::vector<const char*>& extensions, Context::GetSurfaceCallback, int windowWidth, int windowHeight);
    void Quit();
    Renderer* GetRenderer();

}