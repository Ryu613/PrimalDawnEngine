#include "application_context.hpp"

namespace PrimalDawnBites {
    std::unique_ptr<PrimalDawn::Engine> ApplicationContext::engine = nullptr;
    
    ApplicationContext::ApplicationContext(const std::string& name)
        : appName(name) {
        engine = std::make_unique<PrimalDawn::Engine>();
        LOG_INFO(name + "启动中...");
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        LOG_INFO(appName + "正在初始化");
        staticPluginLoader.load();
    }

    void ApplicationContext::closeApp() {

    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return engine.get();
    }
}