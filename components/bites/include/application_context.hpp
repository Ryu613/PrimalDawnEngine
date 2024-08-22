#pragma once
#include "prequisites.hpp"
#include "macro.hpp"
#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
    public:
        StaticPluginLoader staticPluginLoader;
        static std::unique_ptr<PrimalDawn::Engine> engine;
    public:
        ApplicationContext(const PrimalDawn::String& name);
        ~ApplicationContext();
        
        void initApp();
        void closeApp();
        PrimalDawn::Engine* getEngine() const;
    protected:
        PrimalDawn::String& appName;

    };
}