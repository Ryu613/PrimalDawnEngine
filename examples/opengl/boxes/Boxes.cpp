#include "Boxes.hpp"

#include "platform/WindowSystemFactory.hpp"
#include "core/Logging.hpp"
#include "core/Engine.hpp"
#include "core/SwapChain.hpp"
#include "core/Scene.hpp"
#include "core/Renderer.hpp"
#include "core/View.hpp"
#include "platform/Platform.hpp"
#include "BoxesRenderer.hpp"

using namespace pd;

Boxes::Boxes() {
}

bool Boxes::prepare(const AppConfig& options) {
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

void Boxes::finish() {
    mEngine->getPlatform()->getRenderSystem()->endRenderPass();
    mWindowSystem->close();
    Engine::destroy(mEngine.get());
}

void Boxes::run() {
    BoxesRenderer renderer;
    renderer.renderBoxes(mWindowSystem.get());
}

void Boxes::initWindow() {
    WindowSystem::WindowSystemOptions winOpt{
        "Hello-Triangle"
    };
    mWindowSystem = WindowSystemFactory::createWindowSystem(winOpt);
}

void Boxes::initRenderSystem() {
    LOG_INFO("creating swapchain...")
    mSwapChain = mEngine->createSwapChain(mWindowSystem.get());
}

int main() {
    Boxes boxes;
    AppConfig config;
    boxes.prepare(config);
    boxes.run();
    return 0;
}


