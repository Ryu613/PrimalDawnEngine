#include<string>
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

    void Engine::installPlugin(Plugin* p) {
        p->install();
    }

    void Engine::startRendering() {
        // äÖÈ¾Ñ­»·
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

    SceneManager* Engine::createSceneManager() {
        return new SceneManager();
    }
}