#pragma once

#include <string>

#include "platform/platform_config.hpp"

namespace primaldawn {
    struct EngineConfig {
        std::string app_name{ "default" };
        //RenderSystemConfig render_system_config;
        PlatformConfig platform_config;
        //RendererConfig renderer_config;
        bool enable_debug = false;
    };

} // namespace primaldawn
