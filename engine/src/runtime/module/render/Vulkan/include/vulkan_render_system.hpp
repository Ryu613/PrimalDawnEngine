#include "render_system.hpp"

namespace PrimalDawn {
    class VulkanRenderSystem : public RenderSystem {
    public:
        VulkanRenderSystem();
        ~VulkanRenderSystem();
        void shutdown();
    };
}