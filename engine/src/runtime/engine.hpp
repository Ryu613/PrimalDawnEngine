#pragma once
#include "core/render_system.hpp"

namespace PrimalDawn
{
    class Engine {
    public:
        Engine();
        ~Engine();
        void init();
        void shutdown();
        void setRenderSystem(RenderSystem* renderSystem);
    private:
        RenderSystem* currentRenderer;
        void _createWindow();
    };
}