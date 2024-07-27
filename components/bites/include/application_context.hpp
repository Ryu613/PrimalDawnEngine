#pragma once
#include <string>
#include "engine.hpp"

namespace PrimalDawnBites {
    class ApplicationContext {
    public:
        ApplicationContext(const std::string& name);
        ~ApplicationContext();
        
        void initApp();
        void closeApp();
    protected:
        std::string appName;
        PrimalDawn::Engine* engine;

    };
}