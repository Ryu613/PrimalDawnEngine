#include "macro.hpp"
#include "application_context.hpp"
#include "global_context.hpp"

namespace PrimalDawnBites {
    PrimalDawn::Engine* ApplicationContext::engine = nullptr;
    
    ApplicationContext::ApplicationContext(const std::string& name) {
        appName = name;
        PrimalDawn::global_runtime_context.startSystems();
        //LOG_INFO("app init");
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        PrimalDawn::Engine::init();
        staticPluginLoader.load();
        engine = &PrimalDawn::Engine::Instance();
    }

    void ApplicationContext::closeApp() {

    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return engine;
    }
}