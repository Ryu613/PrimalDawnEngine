#include "application/application.hpp"

#include "primaldawn/engine.hpp"

namespace primaldawn {
    Application::Application(ApplicationConfig config)
        : application_config_(std::move(config)) {
        engine_ = Engine::Create(application_config_.engine_config);
        close_ = false;
    }

    Application::~Application() {
    }

     void Application::SetupScene() {};
     void Application::SetupWindow() {};
     void Application::SetupEngine() {};
     void Application::Run() {
         // 执行完要销毁
         Close();
     };
     void Application::Close() {
         Engine::Destroy(engine_);
         close_ = true;
     };
} // namespace primaldawn
