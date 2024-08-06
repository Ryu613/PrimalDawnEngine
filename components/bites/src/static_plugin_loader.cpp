#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    void StaticPluginLoader::load() {
        using namespace PrimalDawn;
        PrimalDawn::Plugin* plugin = NULL;
#ifdef RENDERSYSTEM_OPENGL4
        plugin = new GL4Plugin();
        plugins.push_back(plugin);
#endif
#ifdef RENDERSYSTEM_VULKAN
        plugin = new VulkanPlugin();
        plugins.push_back(plugin);
#endif
        Engine& engine = Engine::Instance();
        for (auto& p : plugins) {
            engine.installPlugin(p);
        }
    }
}