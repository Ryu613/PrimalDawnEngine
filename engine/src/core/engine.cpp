#include "core/Engine.hpp"
#include "core/Logging.hpp"
#include "platform/PlatformFactory.hpp"

namespace pd {

    Engine* Engine::create(EngineConfig& config) {
        return new Engine(config);
    }

    Engine::Engine(EngineConfig& engineConfig)
        : mEngineConfig(engineConfig) {
        init();
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

    SwapChain* Engine::createSwapChain(WindowSystem* windowSystem) noexcept {
        return nullptr;
    }

    Renderer* Engine::createRenderer() noexcept {
        return nullptr;
    }

    Scene* Engine::createScene() noexcept {
        return nullptr;
    }

    View* Engine::createView() noexcept {
        return nullptr;
    }
}



