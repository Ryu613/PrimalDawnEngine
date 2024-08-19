#pragma once

#include <memory>
#include "macro.hpp"
#include "singleton.hpp"
#include "plugin.hpp"
#include "render_system.hpp"
#include "scene_manager.hpp"
#include "log_manager.hpp"
#include "asset_manager.hpp"

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
        SceneManager* getSceneManager();
        void installPlugin(Plugin* p);
        void startRendering();
        bool renderOneFrame();
    private:
        void _createWindow();
        bool _updateAllRenderTargets();
    private:
        std::unique_ptr<RenderSystem> mRenderer;
        std::unique_ptr<LogManager> mLogManager;
        std::unique_ptr<SceneManager> mSceneManager;
        std::unique_ptr<AssetManager> mAssetManager;
    };
}