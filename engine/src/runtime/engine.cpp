#include "engine.hpp"

namespace PrimalDawn {
    Engine::Engine() {
        
    }

    void Engine::init() {
        _createWindow();
    }

    void Engine::_createWindow() {
        currentRenderer->init();
    }
}