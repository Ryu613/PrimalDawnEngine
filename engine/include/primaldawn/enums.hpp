#pragma once

#include <cstdint>

namespace primaldawn {
    enum class RenderSystemType : uint8_t {
        DEFAULT = 0,
        OPENGL = 1,
        VULKAN = 2,
        METAL = 3,
    };

    enum class OS : uint8_t {
        WINDOWS = 1,
        LINUX = 2,
        MACOS = 3,
    };

    enum class WindowSystemType : uint8_t {
        DEFAULT = 0,
        SDL2 = 1,
        GLFW3 = 2,
    };

    enum class WindowMode : uint8_t {
        DEFAULT = 0,
        HEADLESS = 1,
        FULLSCREEN = 2,
        BORDERLESS = 3,
    };
} // namespace primaldawn
