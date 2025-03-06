#include "platform/RenderSystemFactory.hpp"

#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/rs/vulkan/RenderSystemVulkan.hpp"
#endif

namespace pd {
    std::unique_ptr<RenderSystem> createRenderSystem(OS os, Backend backend) {
    #if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
        LOG_INFO("Render System - Vulkan")
        VulkanConfig vkConfig;
        vkConfig.os = os;
        vkConfig.enableDebug = rsConfig.enableDebug;
        return std::make_unique<RenderSystemVulkan>(vkConfig);
    #else
        LOG_INFO("RenderSystem - Unknown")
        throw std::runtime_error("init Platform failed, Unknown RenderSystem");
    #endif
         return nullptr;
    }
}
