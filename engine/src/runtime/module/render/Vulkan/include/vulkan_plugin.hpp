#include "plugin.hpp"
#include "vulkan_render_system.hpp"
#include "engine.hpp"

namespace PrimalDawn {
    class VulkanPlugin : public Plugin {
        VulkanRenderSystem* renderSystem;
    public:
        VulkanPlugin();
        ~VulkanPlugin();

        void install() override;

        void init() override;

        void shutdown() override;

        void uninstall() override;
    };
}