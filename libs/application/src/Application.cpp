#include "application/Application.h"
#include "core/util/Logging.h"

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
