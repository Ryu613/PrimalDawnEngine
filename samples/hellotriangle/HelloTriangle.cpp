#include "HelloTriangle.h"
#include "platform/WindowSystemSDL.h"
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
    LOG_INFO("creating swapchain...")
    mSwapChain = mEngine->createSwapChain(mWindowSystem.get());
    return true;
}

void HelloTriangle::runOneFrame(float ms) {

}

void HelloTriangle::finish() {

}

void HelloTriangle::run() {
    while (!mClosed && !mWindowSystem->shouldClose()) {
        runOneFrame(1);
    }
}

void HelloTriangle::initWindow() {
    WindowSystemSDL::WindowSystemOptions winOpt{
        "Hello-Triangle"
    };
    mWindowSystem = std::make_unique<WindowSystemSDL>(winOpt);
}

void HelloTriangle::initEngine() {
    mEngine = Engine::Builder().build();
}


