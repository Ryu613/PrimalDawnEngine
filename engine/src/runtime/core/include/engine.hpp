#pragma once

#include <memory>
#include "singleton.hpp"
#include "plugin.hpp"
#include "render_system.hpp"
#include "scene_manager.hpp"
#include "log_manager.hpp"

namespace PrimalDawn
{
    class Engine : public Singleton<Engine> {
    public:
        static Engine& getSingleton();
        static Engine* getSingletonPtr();
        Engine();
        ~Engine();
        void setRenderSystem(RenderSystem* renderSystem);
        RenderSystem* getRenderSystem();
        void installPlugin(Plugin* p);
        void startRendering();
        bool renderOneFrame();
        SceneManager* createSceneManager();
    private:
        void _createWindow();
        bool _updateAllRenderTargets();
    private:
        std::unique_ptr<RenderSystem> mRenderer;
        std::unique_ptr<LogManager> mLogManager;
        SceneManager* mSceneManager;
    };
}