#include "application/application.hpp"

#include <stdexcept>

#include "primaldawn/logging.hpp"
#include "primaldawn/engine.hpp"
#include "primaldawn/scene.hpp"
#include "primaldawn/view.hpp"

namespace primaldawn {
    Application& Application::Get() {
        static Application app;
        return app;
    }

    Application::~Application() {
    }

    Application& Application::Configure(const ApplicationConfig* config) {
        if (configured_) {
            LOGW("you have configured this application, cannot re-configure!")
                return *this;
        }
        if (!config) {
            LOGW("no config specified, use default configuration")
                config_ = ApplicationConfig{};
        }
        else {
            config_ = *config;
        }
        configured_ = true;
        return *this;
    }

    Application& Application::SetupScene(SceneSetupCallback setup) {
        // configure scene and view
        //scene_ = engine_->CreateScene();
        //view_ = engine_->CreateView();
        //view_->SetScene(scene_);
        //camera_ = engine_->CreateCamera();
        if (!setup) {
            LOGW("scene not setup, use default scene!")
            scene_ = engine_->CreateScene();
            //scene_->AddEntity();
        }
        scene_setup_ = true;
        return *this;
    }

    void Application::Run() {
        if (!configured_) {
            throw std::runtime_error("please run Configure() explicitly first!");
        }
        // configure and create engine
        config::Engine engine_config;
        engine_config.app_name = config_.app_name;
        engine_config.enable_debug = config_.enable_debug;
        if (config_.backend == RenderSystemType::DEFAULT) {
#if defined(_WIN32) && defined(PRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
            config_.backend = RenderSystemType::VULKAN;
#elif defined(PRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
            config.backend = RenderSystemType::OPENGL;
#else
            throw std::runtime_error("cannot find a proper backend! application run failed");
#endif
        }
        engine_config.render_system.render_system_type = config_.backend;
        if (config_.window_api == WindowSystemType::DEFAULT) {
            config_.window_api = WindowSystemType::SDL2;
        }
        engine_config.platform.window_system.title = config_.app_name;
        engine_config.platform.window_system_type = config_.window_api;
        engine_config.platform.window_system.headless = config_.window_headless;
        engine_config.platform.window_system.resizable = config_.window_resizable;
        engine_config.platform.window_system.window_height = config_.window_height;
        engine_config.platform.window_system.window_width = config_.window_width;
        engine_ = Engine::Create(&engine_config);
        // TODO renderer
        close_ = false;
        // TODO render loop
        while (!close_) {

        }
        // TODO destroy
        Engine::Destroy(engine_);
        engine_ = nullptr;
    }

    void Application::Close() {
        close_ = true;
    }

    Application::Application() {
        logging::Init();
    }
} // namespace primaldawn
