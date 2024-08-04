#pragma once
#include <string>
#include "engine.hpp"
#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
        StaticPluginLoader staticPluginLoader;
    public:
        ApplicationContext(const std::string& name);
        ~ApplicationContext();
        
        void initApp();
        void closeApp();
    protected:
        std::string appName;

    };
}