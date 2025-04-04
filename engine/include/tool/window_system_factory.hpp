#pragma once

#include <memory>

#include "platform/window_system_config.hpp"

namespace primaldawn {
    class WindowSystem;

    class WindowSystemFactory {
    public:
        static std::unique_ptr<WindowSystem> CreateWindowSystem(WindowSystemConfig config);
    };
} // namespace primaldawn
