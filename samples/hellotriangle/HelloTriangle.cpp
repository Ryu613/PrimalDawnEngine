#include "HelloTriangle.hpp"
#include "platform/ws/sdl2/WindowSystemSDL2.hpp"
#include "core/Logging.hpp"
#include "core/Renderer.hpp"
#include "core/View.hpp"

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
    if (mRenderer->beginFrame(mSwapChain)) {
        mRenderer->render(mView);
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
    WindowSystemSDL2::WindowSystemOptions winOpt{
        "Hello-Triangle"
    };
    mWindowSystem = new WindowSystemSDL2(winOpt); 
}

void HelloTriangle::initEngine() {
    EngineConfig engineConfig{
        .appName = "Hello Triangle",
        .backend = Backend::VULKAN,
        .enableDebug = true
    };
    mEngine = Engine::create(engineConfig);
    LOG_INFO("creating swapchain...")
    mSwapChain = mEngine->createSwapChain(mWindowSystem);
    LOG_INFO("creating renderer...")
    mRenderer = mEngine->createRenderer();
    auto scene = mEngine->createScene();
    LOG_INFO("creating view...")
    mView = mEngine->createView();
    mView->setScene(scene);
    LOG_INFO("setup scene...")
    // 设置相机
    // 设置场景
}


