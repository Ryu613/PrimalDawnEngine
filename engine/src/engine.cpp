#include "core/Engine.h"
#include "core/util/Logging.h"
#include "platform/PlatformFactory.h"

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
    // 初始化vulkan
    LOG_INFO("Initializing backend...")
    mPlatform = PlatformFactory::create(&mBackend);

}

void Engine::setBackend(Backend backend) {
    mBackend = backend;
}

