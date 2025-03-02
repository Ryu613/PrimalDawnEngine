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

    /**
    * @grief whether to skip frame, or do something before rendering
    */
    bool Renderer::beginFrame(SwapChain* swapChain) {
        return true;
    }


    void Renderer::render(const View* view) {
    }

    void Renderer::endFrame() {

    }
}
