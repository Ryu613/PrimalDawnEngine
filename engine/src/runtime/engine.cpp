#include "engine.hpp"

namespace PrimalDawnEngine {

    std::unique_ptr<Renderer> renderer_;

    void Init(std::vector<const char*>& extensions, Context::GetSurfaceCallback cb, int windowWidth, int windowHeight) {
        Context::Init(extensions, cb);
        auto& ctx = Context::Instance();
        ctx.initSwapchain(windowWidth, windowHeight);
        ctx.initRenderProcess();
        ctx.initGraphicsPipeline();
        ctx.swapchain->InitFramebuffers();
        ctx.initCommandPool();

        renderer_ = std::make_unique<Renderer>();
    }

    void Quit() {
        PrimalDawnEngine::Context::Instance().device.waitIdle();
        renderer_.reset();
        Context::Quit();
    }

    Renderer* GetRenderer() {
        return renderer_.get();
    }

}