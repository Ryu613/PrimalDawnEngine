#pragma once
#include "render_system.hpp"
#include "plugin.hpp"

namespace PrimalDawn
{
    class Engine {
    public:
        static Engine& Instance();
        static Engine* init();
        void shutdown();
        void setRenderSystem(RenderSystem* renderSystem);
        void loadPlugins();
        void installPlugin(Plugin* p);
    private:
        Engine();
        ~Engine();
        static Engine* _instance;
        RenderSystem* currentRenderer;
        void _createWindow();
    };
}