#include "macro.hpp"
#include "application_context.hpp"
#include "global_context.hpp"

namespace PrimalDawnBites {
    
    ApplicationContext::ApplicationContext(const std::string& name) {
        appName = name;
        using namespace PrimalDawn;
        global_runtime_context.startSystems();
        LOG_INFO("app init");
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