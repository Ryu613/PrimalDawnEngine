#include "HelloTriangle.h"
#include "platform/SDLWindow.h"
#include "core/util/Logging.h"

using namespace pd;

HelloTriangle::HelloTriangle() {
}

bool HelloTriangle::prepare(const AppConfig& options) {
    if (!Application::prepare(options)) {
        LOG_ERROR("app prepare failed!")
        return false;
    }
    initWindow();
    initEngine();
    return true;
}

void HelloTriangle::runOneFrame(float ms) {

}

void HelloTriangle::finish() {

}

void HelloTriangle::run() {
    while (!mClosed && !mWindow->shouldClose()) {
        runOneFrame(1);
    }
}

void HelloTriangle::initWindow() {
    Window::WindowOptions winOpt{
        "Hello-Triangle"
    };
    mWindow = std::make_unique<SDLWindow>(winOpt);
}

void HelloTriangle::initEngine() {
    mEngine = Engine::Builder().build();
}


