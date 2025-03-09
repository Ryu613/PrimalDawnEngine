#include "core/Renderer.hpp"
#include "core/SwapChain.hpp"
#include "core/engine.hpp"
#include "core/View.hpp"

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
