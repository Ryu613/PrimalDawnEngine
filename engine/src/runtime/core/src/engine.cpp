#include<string>
#include <assert.h>
#include "engine.hpp"

namespace PrimalDawn {

    template<> Engine* Singleton<Engine>::msSingleton = 0;
    Engine* Engine::getSingletonPtr(void) {
        return msSingleton;
    }
    Engine& Engine::getSingleton(void) {
        assert(msSingleton);
        return (*msSingleton);
    }

    Engine::Engine() {
        mLogManager = std::make_unique<LogManager>();
        mAssetManager = std::make_unique<AssetManager>();
        mSceneManager = std::make_unique<SceneManager>();
        LOG_INFO("原初黎明引擎初始化中...");
        LOG_INFO("当前版本: 0.2.0");
    }

    Engine::~Engine() {
        mLogManager.reset();
    }

    void Engine::_createWindow() {
    }

    void Engine::setRenderSystem(RenderSystem* renderer) {
        mRenderer.reset(renderer);
    }

    RenderSystem* Engine::getRenderSystem() {
        return mRenderer.get();
    }

    SceneManager* Engine::getSceneManager() {
        return mSceneManager.get();
    }

    void Engine::installPlugin(Plugin* p) {
        p->install();
    }

    void Engine::startRendering() {
        // 渲染循环
        while (true) {
            if (!renderOneFrame()) {
                break;
            }
        }
    }

    bool Engine::renderOneFrame() {
        //_updateCamera();
        //_updateSceneElements();
        //_renderScene();
        //_swapBuffers();
        return true;
    }

    bool Engine::_updateAllRenderTargets() {
        mRenderer->_updateAllRenderTargets();
        return true;
    }

    //SceneManager* Engine::createSceneManager() {
    //    return new SceneManager();
    //}
}