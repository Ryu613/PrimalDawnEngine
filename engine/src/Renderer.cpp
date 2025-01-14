#include "core/Renderer.h"
#include "core/SwapChain.h"
#include "core/engine.h"
#include "core/View.h"

namespace pd {

    Renderer::Renderer(Engine& engine) :
        mEngine(engine) {

    }

    Renderer::~Renderer() noexcept {

    }

    bool Renderer::beginFrame(SwapChain* swapChain) {
        //TODO
        return true;
    }

    void Renderer::render(const View* view) {

    }

    void Renderer::endFrame() {

    }
}
