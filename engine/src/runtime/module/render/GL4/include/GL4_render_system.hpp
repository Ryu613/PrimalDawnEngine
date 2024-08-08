#pragma once
#include "render_system.hpp"
#include "GL4_window.hpp"
#include <memory>

namespace PrimalDawn {
    class GL4RenderSystem : public RenderSystem {
    public:
        GL4RenderSystem();
        ~GL4RenderSystem();
        void shutdown();
    private:
        std::unique_ptr<GL4Window> _window;
    };
}