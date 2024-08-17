#include "macro.hpp"
#include "application_context.hpp"

namespace PrimalDawnBites {
    PrimalDawn::Engine* ApplicationContext::engine = nullptr;
    
    ApplicationContext::ApplicationContext(const std::string& name) {
        appName = name;
        //LOG_INFO("app init");
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        engine = new PrimalDawn::Engine;
        staticPluginLoader.load();
    }

    void ApplicationContext::closeApp() {

    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return engine;
    }
}