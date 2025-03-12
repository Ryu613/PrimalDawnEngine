#include "platform/RenderSystemFactory.hpp"

#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/rs/vulkan/RenderSystemVulkan.hpp"
#endif

namespace pd {
    std::unique_ptr<RenderSystem> RenderSystemFactory::createRenderSystem(RenderSystemConfig& rsConfig) {
    #if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
        LOG_INFO("Render System - Vulkan")
        VulkanConfig vkConfig;
        vkConfig.os = rsConfig.os;
        vkConfig.enableDebug = rsConfig.enableDebug;
        vkConfig.appName = rsConfig.appName;
        // debug pipeline
        vkConfig.createDebugPipeline = true;
        return std::unique_ptr<RenderSystemVulkan>(new RenderSystemVulkan(vkConfig));
    #else
        LOG_INFO("RenderSystem - Unknown")
        throw std::runtime_error("init Platform failed, Unknown RenderSystem");
    #endif
         return nullptr;
    }
}
