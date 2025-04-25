#pragma once

#include <string>
#include "primaldawn/enums.hpp"

namespace primaldawn::config {

    struct WindowSystemExtent {
        unsigned int width = 1024;
        unsigned int height = 768;
    };

    struct WindowSystem {
        std::string title{};
        WindowSystemMode window_system_mode = WindowSystemMode::DEFAULT;
        bool is_headless = false;
        bool resizable = true;
        WindowSystemExtent extent{ 1024, 768 };
    };

    struct Platform {
        OS os = OS::WINDOWS;
        WindowSystemType window_system_type = WindowSystemType::GLFW3;
        WindowSystem window_system;

    };
    struct RenderSystem {
        std::string app_name{ "default"};
        std::string engine_name{ "Primal Dawn" };
        OS os = OS::WINDOWS;
        RenderSystemType render_system_type = RenderSystemType::NOOP;
        bool enable_debug = false;
    };
    struct Renderer {

    };
    struct CameraConfig {
        CameraProjectionType cam_proj_type = CameraProjectionType::PERSPECTIVE;
        CameraFovType cam_fov_type = CameraFovType::HORIZONTAL;
    };
	struct Engine {
        std::string app_name{ "default" };
        bool enable_debug = false;
        Platform platform = {};
        RenderSystem render_system = {};
        Renderer renderer = {};

	};
} // namespace primaldawn::config
