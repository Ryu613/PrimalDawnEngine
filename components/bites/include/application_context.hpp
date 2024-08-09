#pragma once
#include <string>
#include "engine.hpp"
#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
    public:
        StaticPluginLoader staticPluginLoader;
        static PrimalDawn::Engine* engine;
    public:
        ApplicationContext(const std::string& name);
        ~ApplicationContext();
        
        void initApp();
        void closeApp();
        PrimalDawn::Engine* getEngine() const;
    protected:
        std::string appName;

    };
}