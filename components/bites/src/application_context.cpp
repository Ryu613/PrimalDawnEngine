#include "application_context.hpp"

namespace PrimalDawnBites {
    std::unique_ptr<PrimalDawn::Engine> ApplicationContext::engine = nullptr;
    
    ApplicationContext::ApplicationContext(const PrimalDawn::String& name)
        : appName((PrimalDawn::String&)name) {
        engine = std::make_unique<PrimalDawn::Engine>();
        LOG_INFO("Ӧ�� [ " + appName + "] ������...");
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        LOG_INFO("Ӧ�� [ " + appName + "] ���ڳ�ʼ��");
        staticPluginLoader.load();
    }

    void ApplicationContext::closeApp() {

    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return engine.get();
    }
}