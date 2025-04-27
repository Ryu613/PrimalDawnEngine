#pragma once

#include <string>
#include "primaldawn/enums.hpp"

namespace primaldawn::config {

    struct WindowSystem {
        std::string title{};
        WindowSystemMode window_system_mode = WindowSystemMode::DEFAULT;
        bool headless = false;
        bool resizable = true;
        size_t window_height = 1024;
        size_t window_width = 768;
    };

    struct Platform {
        OS os = OS::WINDOWS;
        WindowSystemType window_system_type = WindowSystemType::SDL2;
        WindowSystem window_system;

    };
    struct RenderSystem {
        std::string app_name{ "default"};
        std::string engine_name{ "Primal Dawn" };
        OS os = OS::WINDOWS;
        RenderSystemType render_system_type = RenderSystemType::VULKAN;
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
        Platform platform;
        RenderSystem render_system;
        Renderer renderer;

	};
} // namespace primaldawn::config
