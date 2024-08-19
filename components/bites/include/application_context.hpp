#pragma once
#include <string>
#include "macro.hpp"
#include "engine.hpp"
#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
    public:
        StaticPluginLoader staticPluginLoader;
        static std::unique_ptr<PrimalDawn::Engine> engine;
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