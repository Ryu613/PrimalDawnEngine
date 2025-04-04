#include "core/Engine.hpp"

#include "core/Logging.hpp"
#include "platform/PlatformFactory.hpp"
#include "core/Renderer.hpp"
#include "core/Scene.hpp"
#include "core/View.hpp"
#include "core/SwapChain.hpp"

namespace pd {

    std::unique_ptr<Engine> Engine::create(EngineConfig& config) {
        return std::unique_ptr<Engine>(new Engine(config));
    }

    void Engine::destroy(Engine* engine) {

    }

    Engine::Engine(EngineConfig& engineConfig)
        : mEngineConfig(engineConfig) {
        init();
    }

    Engine::~Engine() {
    }

    void Engine::init() {
        // 初始化日志
        logging::init();
        LOG_INFO("logger initialized")
        // 初始化平台层
        LOG_INFO("initializing platform")
        PlatformConfig pConfig;
        pConfig.appName = mEngineConfig.appName;
        pConfig.backend = mEngineConfig.backend;
        pConfig.enableDebug = mEngineConfig.enableDebug;
        mPlatform = PlatformFactory::createPlatform(pConfig);
        LOG_INFO("platform initialized")
    }

    std::unique_ptr<SwapChain> Engine::createSwapChain(WindowSystem* windowSystem) noexcept {
        return mPlatform->getRenderSystem()->createSwapChain(*this, windowSystem);
    }

    std::unique_ptr<Renderer> Engine::createRenderer() noexcept {
        return std::make_unique<Renderer>(*this);
    }

    std::unique_ptr<Scene> Engine::createScene() noexcept {
        return std::make_unique<Scene>(*this);
    }

    std::unique_ptr<View> Engine::createView() noexcept {
        return std::make_unique<View>(*this);
    }

    Backend Engine::getBackend() const noexcept {
        return mEngineConfig.backend;
    }

    Platform* Engine::getPlatform() const noexcept {
        return mPlatform.get();
    }
}



