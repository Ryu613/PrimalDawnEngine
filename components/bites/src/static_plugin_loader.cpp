#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    void StaticPluginLoader::load() {
        PrimalDawn::Plugin* plugin = NULL;
#ifdef RENDERSYSTEM_OPENGL4
        plugin = new PrimalDawn::GL4Plugin();
        mPlugins.push_back(plugin);
#endif
#ifdef RENDERSYSTEM_VULKAN
        plugin = new VulkanPlugin();
        mPlugins.push_back(plugin);
#endif
        PrimalDawn::Engine& engine = PrimalDawn::Engine::getSingleton();
        for (auto& p : mPlugins) {
            engine.installPlugin(p);
        }
    }

    void StaticPluginLoader::unload() {

    }
}