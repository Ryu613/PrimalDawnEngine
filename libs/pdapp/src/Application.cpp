#include "Application.h"

using namespace pd;

Application& Application::get() {
    static Application app;
    return app;
}

bool Application::prepare(const AppConfig& options) {

}

void Application::runOneFrame(float ms) {

}

void Application::finish() {

}


Application::Application() {
    mName{ "default" };
}
