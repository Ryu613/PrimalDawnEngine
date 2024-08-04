#include "application_context.hpp"

namespace PrimalDawnBites {
    
    ApplicationContext::ApplicationContext(const std::string& name) {
        appName = name;
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        PrimalDawn::Engine::init();
        staticPluginLoader.load();
    }

    void ApplicationContext::closeApp() {

    }
}