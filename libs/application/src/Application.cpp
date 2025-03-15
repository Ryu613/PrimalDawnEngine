#include "application/Application.hpp"
#include "core/Logging.hpp"
#include "platform/WindowSystem.hpp"
#include "core/Engine.hpp"
#include "core/SwapChain.hpp"
#include "core/Scene.hpp"
#include "core/Renderer.hpp"
#include "core/View.hpp"

using namespace pd;

bool Application::prepare(const AppConfig& options) {
    LOG_INFO("Application {} initializing", options.appName)
    mName = options.appName;

    return true;
}

void Application::runOneFrame(float ms) {

}

void Application::finish() {

}


Application::Application()
    : mName{"default"} {
}

Application::~Application() {

}
