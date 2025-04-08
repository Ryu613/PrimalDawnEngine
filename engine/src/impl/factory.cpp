#include "impl/factory.hpp"

#include <memory>
#include <stdexcept>

#include "primaldawn/platform.hpp"
#include "primaldawn/config.hpp"
#if defined(WIN32)
#include "platform/os/platform_windows.hpp"
#endif

#if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
#include "platform/render_system/render_system_vulkan.hpp"
#elif defined(PRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
#include "platform/render_system/render_system_opengl.hpp"
#endif

#include "primaldawn/logging.hpp"

namespace primaldawn::factory {

    std::unique_ptr<PdPlatform> CreatePlatform(config::Platform config) {
    #if defined(WIN32)
        LOGI("Platform is {}", "Windows")
        return std::make_unique<PlatformWindows>(std::move(config));
    #else
        LOG_INFO("Platform is {}", "Vulkan - Unknown OS")
        return nullptr;
    #endif
    }

    std::unique_ptr<PdRenderSystem> CreateRenderSystem(config::RenderSystem config) {
        if (config.render_system_type == RenderSystemType::OPENGL) {
            LOGI("RenderSystem - OpenGL")
        #if defined(PRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
            return std::make_unique<RenderSystemOpenGL>(config);
        #else
             throw std::runtime_error("init Platform failed, OpenGL not supported !");
        #endif
        }
        else if (config.render_system_type == RenderSystemType::VULKAN) {
            LOGI("Render System - Vulkan")
        #if defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
            return std::make_unique<RenderSystemVulkan>(config);
        #else
            throw std::runtime_error("init Platform failed, Vulkan not supported !");
        #endif
        }
        else {
            throw std::runtime_error("init Platform failed, render system not supported !");
        }
    }

} // namespace primaldawn::factory
