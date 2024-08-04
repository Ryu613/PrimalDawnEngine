#include "vulkan_plugin.hpp"

namespace PrimalDawn {
    VulkanPlugin::VulkanPlugin() {
        renderSystem = 0;
    }
    VulkanPlugin::~VulkanPlugin() {}
    
    void VulkanPlugin::install() {
        renderSystem = new VulkanRenderSystem();
        Engine::Instance().setRenderSystem(renderSystem);
    }

    void VulkanPlugin::init() {}

    void VulkanPlugin::shutdown() {}

    void VulkanPlugin::uninstall() {}
}