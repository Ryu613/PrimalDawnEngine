#pragma once
#include "plugin.hpp"
#include "vulkan_plugin.hpp"
#include "engine.hpp"
#include <vector>

namespace PrimalDawnBites {
    class StaticPluginLoader {
        std::vector<PrimalDawn::Plugin*> plugins;
    public:
        void load();
        void unload();
    };
}