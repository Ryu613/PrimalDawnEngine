#pragma once

#include <string>
#include "primaldawn/platform_enum.hpp"

namespace primaldawn::config {
    struct Platform {
        WindowSystemType window_system = WindowSystemType::GLFW3;
    };
    struct RenderSystem {
        std::string engine_name{ "Primal Dawn" };
        RenderSystemType render_system_type = RenderSystemType::NOOP;
    };
    struct Renderer {

    };
	struct Engine {
        std::string app_name{ "default" };
        bool enable_debug = false;
        Platform platform = {};
        RenderSystem render_system = {};
        Renderer renderer = {};

	};
} // namespace primaldawn::config
