#include "application_context.hpp"

namespace PrimalDawnBites {
    
    ApplicationContext::ApplicationContext(const std::string& name) {
        appName = name;
        engine = NULL;
    }
    void ApplicationContext::initApp() {
        engine = new PrimalDawn::Engine();
        engine->init();
    }

    void ApplicationContext::closeApp() {

    }
}