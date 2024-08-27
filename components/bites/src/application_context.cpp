#include "application_context.hpp"

namespace PrimalDawnBites {
    std::unique_ptr<PrimalDawn::Engine> ApplicationContext::mEngine = nullptr;

    ApplicationContext::ApplicationContext(const PrimalDawn::String& name)
        : mAppName((PrimalDawn::String&)name) {
        mEngine = std::make_unique<PrimalDawn::Engine>();
        LOG_INFO("应用 [ " + mAppName + " ] 启动中...");
        mStaticPluginLoader = std::make_unique<StaticPluginLoader>();
    }
    ApplicationContext::~ApplicationContext() {
    }
    void ApplicationContext::initApp() {
        LOG_INFO("应用 [ " + mAppName + " ] 正在初始化");
        mStaticPluginLoader->load();
    }

    void ApplicationContext::closeApp() {
        ApplicationContext::mEngine.release();
    }

    PrimalDawn::Engine* ApplicationContext::getEngine() const {
        return mEngine.get();
    }
}