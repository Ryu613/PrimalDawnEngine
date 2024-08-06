#pragma once
#include "render_system.hpp"

namespace PrimalDawn {
    class GL4RenderSystem : public RenderSystem {
    public:
        GL4RenderSystem();
        ~GL4RenderSystem();
        void shutdown();
    };
}