#pragma once
#include "render_system.hpp"
#include "plugin.hpp"
#include <memory>

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
        void _createWindow();
        static Engine* _instance;
        std::unique_ptr<RenderSystem> currentRenderer;
    };
}