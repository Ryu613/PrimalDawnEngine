#include "HelloTriangle.hpp"

#include "primaldawn/scene.hpp"

namespace primaldawn {

    HelloTriangle::HelloTriangle(ApplicationConfig config)
      : Application(std::move(config)) {
    }
    HelloTriangle::~HelloTriangle() {

    }
    void HelloTriangle::Prepare() {
        SetupScene();
    }
    void HelloTriangle::SetupScene() {
        Scene* scene = engine_->CreateScene();
        //Entity triangle = EntityManager.
        //scene->addEntity()
        //scene->CreateView()

    }
    void HelloTriangle::Run() {
        
    }
    void HelloTriangle::Close() {
        Application::Close();
    }

    //bool HelloTriangle::prepare(const AppConfig& options) {
    //    if (!Application::prepare(options)) {
    //        LOG_ERROR("app prepare failed!")
    //            return false;
    //    }
    //    LOGI("initializing window system...")
    //    initWindow();
    //    LOGI("initializing render system...")
    //    initRenderSystem();
    //    LOGI("creating renderer...")
    //    mRenderer = mEngine->createRenderer();
    //    LOGI("creating scene...")
    //     mScene = mEngine->createScene();
    //    LOGI("creating view...")
    //    mView = mEngine->createView();
    //    mView->setScene(mScene.get());
    //    LOGI("setup scene...")
    //    // TODO 初始化imgui
    //    return true;
    //}

    //void HelloTriangle::runOneFrame(float ms) {
    //    if (mRenderer->beginFrame(mSwapChain.get())) {
    //        mRenderer->render(mView.get());
    //        mRenderer->endFrame();
    //    }
    //}

    //void HelloTriangle::finish() {
    //    mEngine->getPlatform()->getRenderSystem()->endRenderPass();
    //    mWindowSystem->close();
    //    Engine::destroy(mEngine.get());
    //}

    //void HelloTriangle::run() {
    //    mEngine->getPlatform()->getRenderSystem()->beginRenderPass();
    //    while (!mWindowSystem->shouldClose()) {
    //        mWindowSystem->processInput();
    //        runOneFrame(1);
    //        mWindowSystem->doEvents();
    //    }
    //}

    //void HelloTriangle::initWindow() {
    //    WindowSystem::WindowSystemOptions winOpt{
    //        "Hello-Triangle"
    //    };
    //    mWindowSystem = WindowSystemFactory::createWindowSystem(winOpt);
    //}

    //void HelloTriangle::initRenderSystem() {
    //    LOGI("creating swapchain...")
    //        mSwapChain = mEngine->createSwapChain(mWindowSystem.get());
    //}
} // namespace primaldawn



