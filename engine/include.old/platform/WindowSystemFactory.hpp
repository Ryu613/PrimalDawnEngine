#pragma once

#include <memory>

#include "platform/WindowSystem.hpp"

namespace pd {
    class WindowSystemFactory {
    public:
        static std::unique_ptr<WindowSystem> createWindowSystem(WindowSystem::WindowSystemOptions& winOpt);
    };
}
