#include "engine.hpp"
#include "render_system.hpp"
#include <string>

namespace PrimalDawn {
    Engine* Engine::_instance = nullptr;

    Engine& Engine::Instance() {
        return *_instance;
    }

    Engine::Engine() {
        currentRenderer = nullptr;
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
        currentRenderer = renderer;
    }

    void Engine::loadPlugins() {
    }

    void Engine::installPlugin(Plugin* p) {
        p->install();
    }
}