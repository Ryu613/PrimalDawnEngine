#pragma once

#include <string>
#include "primaldawn/platform_enum.hpp"

namespace primaldawn::config {

    struct WindowSystemExtent {
        unsigned int width = 1024;
        unsigned int height = 768;
    };

    struct WindowSystem {
        std::string title{};
        WindowSystemMode windowSystemMode = WindowSystemMode::DEFAULT;
        bool resizable = true;
        WindowSystemExtent extent{ 1024, 768 };
    };

    struct Platform {
        WindowSystemType window_system_type = WindowSystemType::GLFW3;
        WindowSystem window_system;

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
