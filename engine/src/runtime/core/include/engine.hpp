#pragma once

#include <memory>
#include "plugin.hpp"
#include "render_system.hpp"

namespace PrimalDawn
{
    class Engine {
    public:
        static Engine& Instance();
        static Engine* init();
        void shutdown();
        void setRenderSystem(PrimalDawn::RenderSystem* renderSystem);
        PrimalDawn::RenderSystem* getRenderSystem();
        void loadPlugins();
        void installPlugin(Plugin* p);
        void startRendering();
        bool renderOneFrame();
    private:
        Engine();
        ~Engine();
        void _createWindow();
        bool _updateAllRenderTargets();
        static Engine* _instance;
        std::unique_ptr<PrimalDawn::RenderSystem> currentRenderer;
    };
}