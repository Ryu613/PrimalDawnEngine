#include "core/Renderer.hpp"
#include "core/SwapChain.hpp"
#include "core/Engine.hpp"
#include "core/View.hpp"
#include "platform/Platform.hpp"

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
        // TODO build framegraph
        auto renderSystem = mEngine.getPlatform()->getRenderSystem();
        //uint32_t imageIndex = mSwapChain->acquire();
        //renderSystem->beginRenderPass();
        //renderSystem->draw(imageIndex);
        //renderSystem->endRenderPass();

    }

    void Renderer::endFrame() {

    }
}
