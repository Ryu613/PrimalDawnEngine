#include "core/Engine.hpp"
#include "core/Logging.hpp"
#include "core/RenderSystem.hpp"
#include "core/Renderer.hpp"
#include "core/View.hpp"
#include "core/Scene.hpp"
#include "platform/PlatformFactory.hpp"

namespace pd {

    std::unique_ptr<Engine> Engine::create(EngineConfig& config) {
        return std::make_unique<Engine>(config);
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
        pConfig.backend = mEngineConfig.backend;
        pConfig.enableDebug = mEngineConfig.enableDebug;
        mPlatform = PlatformFactory::createPlatform(pConfig);
        LOG_INFO("platform initialized")
        RenderSystemConfig rsConfig;
        rsConfig.enableDebug = mEngineConfig.enableDebug;
    }

    std::unique_ptr<SwapChain> Engine::createSwapChain(WindowSystem* windowSystem) noexcept {
        return mPlatform->createSwapChain(*this, windowSystem);
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
}



