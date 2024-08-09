#pragma once
#include "plugin.hpp"
#ifdef RENDERSYSTEM_OPENGL4
#include "GL4_plugin.hpp"
#endif
#ifdef RENDERSYSTEM_VULKAN
#include "vulkan_plugin.hpp"
#endif

#include <vector>
#include "engine.hpp"

namespace PrimalDawnBites {
    class StaticPluginLoader {
    public:
        std::vector<PrimalDawn::Plugin*> mPlugins;
    public:
        void load();
        void unload();
    };
}