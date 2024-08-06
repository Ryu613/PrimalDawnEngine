#pragma once
#include "plugin.hpp"
#ifdef RENDERSYSTEM_OPENGL4
#include "GL4_plugin.hpp"
#endif
#ifdef RENDERSYSTEM_VULKAN
#include "vulkan_plugin.hpp"
#endif

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