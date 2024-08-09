#include<string>
#include "engine.hpp"
#include "render_system.hpp"

namespace PrimalDawn {
    Engine* Engine::_instance = nullptr;

    Engine& Engine::Instance() {
        return *_instance;
    }

    Engine::Engine() {
        currentRenderer.reset();
        loadPlugins();
    }

    Engine::~Engine() {

    }

   Engine* Engine::init() {
        _instance = new Engine();
        return _instance;
    }

    void Engine::_createWindow() {
    }

    void Engine::setRenderSystem(RenderSystem* renderer) {
        currentRenderer.reset(renderer);
    }

    RenderSystem* Engine::getRenderSystem() {
        return currentRenderer.get();
    }

    void Engine::loadPlugins() {
    }

    void Engine::installPlugin(Plugin* p) {
        p->install();
    }

    void Engine::startRendering() {
        while (true) {
            if (!renderOneFrame()) {
                break;
            }
        }
    }

    bool Engine::renderOneFrame() {
        if (!_updateAllRenderTargets()) {
            return false;
        }
        return true;
    }

    bool Engine::_updateAllRenderTargets() {
        currentRenderer->_updateAllRenderTargets();
        return true;
    }
}