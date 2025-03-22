#include "platform/RenderSystemFactory.hpp"

#include <stdexcept>
#include "core/Logging.hpp"

#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/rs/vulkan/RenderSystemVulkan.hpp"
#elif defined(PRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
#include "platform/rs/opengl/RenderSystemOpenGL.hpp"
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
    #elif defined(PRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
        LOG_INFO("RenderSystem - OpenGL")
        OpenGLConfig glConfig;
        return std::make_unique<RenderSystemOpenGL>(glConfig);
    #else
        throw std::runtime_error("init Platform failed, Unknown RenderSystem");
    #endif
         return nullptr;
    }
}
