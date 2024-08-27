#pragma once
#include "prequisites.hpp"
#include "macro.hpp"
#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
    public:
        ApplicationContext(const PrimalDawn::String& name);
        ~ApplicationContext();
        
        void initApp();
        void closeApp();
        PrimalDawn::Engine* getEngine() const;
    protected:
        std::unique_ptr<StaticPluginLoader> mStaticPluginLoader;
        static std::unique_ptr<PrimalDawn::Engine> mEngine;
        PrimalDawn::String& mAppName;

    };
}