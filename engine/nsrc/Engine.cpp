#include "core/Engine.hpp"
#include "Logging.hpp"
#include "platform/PlatformFactory.hpp"

namespace pd {
    Engine::Engine(Config config)
      : mEngineConfig(engineConfig) {
        logging::init();
        LOGI("Engine initializing...")
        mPlatform = PlatformFactory::createPlatform(mEngineConfig.platformConfig);
        mRenderSystem = RenderSystemFactory::createRenderSystem(mEngineConfig.renderSystemConfig);
        mRenderer = RendererFactory::createRenderer(mEngineConfig.rendererConfig);
        LOGI("Engine initialized")
    }

    Engine::~Engine() {

    }

    std::unique_ptr<Engine> Engine::create(Config engineConfig) {
        try {
            return std::unique_ptr<Engine>(new Engine(std::move(engineConfig)));
        }
        catch (const std::exception& e) {
            LOGE("Engine creation failed: {}", e.what());
            return nullptr;
        }
    }

    void Engine::shutdown() {
        mIsRunning = false;
    }

    void Engine::addView(std::unique_ptr<View> view) {
        if (view) {
            mViews.push_back(std::move(view));
        }
    }

    void Engine::run() {
        mIsRunning = true;
    }
}
