#include "HelloTriangle.hpp"

#include "platform/WindowSystemFactory.hpp"
#include "core/Logging.hpp"
#include "core/Engine.hpp"
#include "core/SwapChain.hpp"
#include "core/Scene.hpp"
#include "core/Renderer.hpp"
#include "core/View.hpp"
#include "platform/Platform.hpp"

using namespace pd;

HelloTriangle::HelloTriangle() {
}

bool HelloTriangle::prepare(const AppConfig& options) {
    if (!Application::prepare(options)) {
        LOG_ERROR("app prepare failed!")
        return false;
    }
    LOG_INFO("initializing window system...")
    initWindow();
    LOG_INFO("initializing render system...")
    initRenderSystem();
    LOG_INFO("creating renderer...")
    mRenderer = mEngine->createRenderer();
    LOG_INFO("creating scene...")
    mScene = mEngine->createScene();
    LOG_INFO("creating view...")
    mView = mEngine->createView();
    mView->setScene(mScene.get());
    LOG_INFO("setup scene...")
    // TODO 初始化imgui
    return true;
}

void HelloTriangle::runOneFrame(float ms) {
    if (mRenderer->beginFrame(mSwapChain.get())) {
        mRenderer->render(mView.get());
        mRenderer->endFrame();
    }
}

void HelloTriangle::finish() {
    mEngine->getPlatform()->getRenderSystem()->endRenderPass();
    mWindowSystem->close();
    Engine::destroy(mEngine.get());
}

void HelloTriangle::run() {
    mEngine->getPlatform()->getRenderSystem()->beginRenderPass();
    while (!mWindowSystem->shouldClose()) {
        mWindowSystem->processInput();
        runOneFrame(1);
        mWindowSystem->doEvents();
    }
}

void HelloTriangle::initWindow() {
    WindowSystem::WindowSystemOptions winOpt{
        "Hello-Triangle"
    };
    mWindowSystem = WindowSystemFactory::createWindowSystem(winOpt);
}

void HelloTriangle::initRenderSystem() {
    LOG_INFO("creating swapchain...")
    mSwapChain = mEngine->createSwapChain(mWindowSystem.get());
}


