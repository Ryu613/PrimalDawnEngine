#include "application/application.hpp"

#include "primaldawn/engine.hpp"

namespace primaldawn {
    Application::Application(ApplicationConfig config)
        : application_config_(std::move(config)) {
        engine_ = Engine::Create(application_config_.engine_config);
        close_ = false;
    }

    Application::~Application() {
        Engine::ShutDown(engine_);
    }

     void Application::SetupScene() {};
     void Application::SetupWindow() {};
     void Application::SetupEngine() {};
     void Application::Run() {
         // 执行完要销毁
         Engine::ShutDown(engine_);
         engine_ = nullptr;
     };
     void Application::Close() {
         close_ = true;
     };
} // namespace primaldawn
