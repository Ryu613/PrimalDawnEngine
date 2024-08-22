#include "application_context.hpp"

namespace PrimalDawnBites {
    std::unique_ptr<PrimalDawn::Engine> ApplicationContext::engine = nullptr;
    
    ApplicationContext::ApplicationContext(const PrimalDawn::String& name)
        : appName((PrimalDawn::String&)name) {
        engine = std::make_unique<PrimalDawn::Engine>();
        LOG_INFO("应用 [ " + appName + "] 启动中...");
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        LOG_INFO("应用 [ " + appName + "] 正在初始化");
        staticPluginLoader.load();
    }

    void ApplicationContext::closeApp() {

    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return engine.get();
    }
}