#include "application/application.hpp"

#include "primaldawn/engine.hpp"

namespace primaldawn {
    Application::Application(ApplicationConfig config)
        : application_config_(std::move(config)) {
        engine_ = Engine::Create(config.engine_config);
    }

    Application::~Application() {
        engine_.reset();
    }

     void Application::SetupScene() {};
     void Application::SetupWindow() {};
     void Application::SetupEngine() {};
     void Application::Run() {};
     void Application::Close() {};
} // namespace primaldawn
