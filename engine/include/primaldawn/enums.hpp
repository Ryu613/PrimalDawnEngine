#pragma once

namespace primaldawn {
    enum class RenderSystemType {
        NOOP = 0,
        OPENGL = 1,
        VULKAN = 2,
        METAL = 3,
        D3DX12 = 4,
        UNKWONN = 99,
    };

    enum class OS {
        WINDOWS = 1,
        LINUX = 2,
        MACOS = 3,
        UNKNOWN = 99,
    };

    enum class WindowSystemType {
        SDL2 = 1,
        GLFW3 = 2,
        UNKNOWN = 99,
    };

    enum class WindowSystemMode {
        HEADLESS = 1,
        FULLSCREEN = 2,
        BORDERLESS = 3,
        DEFAULT = 99,
    };

    enum class CameraProjectionType {
        PERSPECTIVE = 1,
        ORTHOGRAPHIC = 2,
    };

    enum class CameraFovType {
        VERTICAL = 1,
        HORIZONTAL = 2,
    };
} // namespace primaldawn
