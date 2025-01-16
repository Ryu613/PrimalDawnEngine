#include "HelloTriangle.h"
#include "platform/WindowSystemSDL.h"
#include "core/util/Logging.h"
#include "core/Renderer.h"
#include "core/View.h"

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
    if (mRenderer->beginFrame(mSwapChain.get())) {
        mRenderer->render(mView.get());
        mRenderer->endFrame();
    }
}

void HelloTriangle::finish() {
    // TODO engine destroy resources
}

void HelloTriangle::run() {
    // TODO 初始化imgui
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
    LOG_INFO("creating swapchain...")
    mSwapChain = mEngine->createSwapChain(mWindowSystem.get());
    LOG_INFO("creating renderer...")
    mRenderer = mEngine->createRenderer();
    auto scene = mEngine->createScene();
    LOG_INFO("creating view...")
    mView = mEngine->createView();
    mView->setScene(scene.get());
    LOG_INFO("setup scene...")
    // 设置相机
    // 设置场景
}


