#include "platform/WindowSystemFactory.hpp"

#include <stdexcept>
#include "core/Logging.hpp"

#if defined(PRIMALDAWN_WSI_TYPE_SDL2)
#include "platform/ws/sdl2/WindowSystemSDL2.hpp"
#elif defined(PRIMALDAWN_WSI_TYPE_GLFW)
#include "platform/ws/glfw3/WindowSystemGLFW3.hpp"
#else
#endif

namespace pd {
    std::unique_ptr<WindowSystem> WindowSystemFactory::createWindowSystem(WindowSystem::WindowSystemOptions& winOpt) {
        #if defined(PRIMALDAWN_WSI_TYPE_SDL2)
            LOG_INFO("WindowSystem - SDL2")
            return std::make_unique<WindowSystemSDL2>(winOpt);
        #elif defined(PRIMALDAWN_WSI_TYPE_GLFW)
            LOG_INFO("WindowSystem - GLFW3")
            return std::make_unique<WindowSystemGLFW3>(winOpt);
        #else
            throw std::runtime_error("init Platform failed, Unknown RenderSystem");
        #endif
        return nullptr;
    }
}
