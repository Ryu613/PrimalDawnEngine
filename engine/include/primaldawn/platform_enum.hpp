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

} // namespace primaldawn
