#include "static_plugin_loader.hpp"

namespace PrimalDawnBites {
    void StaticPluginLoader::load() {
        using namespace PrimalDawn;
        PrimalDawn::Plugin* plugin = NULL;
        plugin = new VulkanPlugin();
        plugins.push_back(plugin);
        Engine& engine = Engine::Instance();
        for (auto& p : plugins) {
            engine.installPlugin(p);
        }
    }
}