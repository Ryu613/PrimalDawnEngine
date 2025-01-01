#include "pdapp/Application.h"
#include "platform/Window.h"

using namespace pd;

bool Application::prepare(const AppConfig& options) {
    return false;
}

void Application::runOneFrame(float ms) {

}

void Application::finish() {

}


Application::Application()
    : mName{"default"} {
}
