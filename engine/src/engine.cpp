#include "core/Engine.h"
#include "core/util/Logging.h"
#include "platform/PlatformFactory.h"
#include "core/Renderer.h"
#include "core/View.h"
#include "core/Scene.h"

using namespace pd;

Engine::Builder::Builder() noexcept = default;
Engine::Builder::~Builder() noexcept = default;
Engine::Builder::Builder(Engine::Builder const& rhs) noexcept = default;
Engine::Builder::Builder(Engine::Builder&& rhs) noexcept = default;
Engine::Builder& Engine::Builder::operator=(Engine::Builder const& rhs) noexcept = default;
Engine::Builder& Engine::Builder::operator=(Engine::Builder&& rhs) noexcept = default;

Engine::Builder& Engine::Builder::backend(Backend backend) noexcept {
    mBackend = backend;
    return *this;
}

std::unique_ptr<Engine> Engine::Builder::build() const {
    return Engine::create(*this);
}

std::unique_ptr<Engine> Engine::create(const Engine::Builder& builder) {
    auto instance = std::make_unique<Engine>();
    instance->setBackend(builder.mBackend);
    instance->init();
    return std::move(instance);
}

void Engine::init() {
    // 初始化日志
    logging::init();
    LOG_INFO("logger initialized")
    // 初始化平台层
    LOG_INFO("initializing platform")
    PlatformConfig pConfig;
    mPlatform = PlatformFactory::create(pConfig);
    LOG_INFO("platform initialized")
}

void Engine::setBackend(Backend backend) {
    mBackend = backend;
}

std::unique_ptr<SwapChain> Engine::createSwapChain(WindowSystem* windowSystem) noexcept {
    return mPlatform->createSwapChain(*this, windowSystem);
}

std::unique_ptr<Renderer> Engine::createRenderer() noexcept {
    return std::make_unique<Renderer>(*this);
}

std::unique_ptr<Scene> Engine::createScene() noexcept {
    return std::make_unique<Scene>(*this);
}

std::unique_ptr<View> Engine::createView() noexcept {
    return std::make_unique<View>(*this);
}

