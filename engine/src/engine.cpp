#include "core/engine.hpp"

#include <exception>

#include "core/logging.hpp"
#include "tool/platform_factory.hpp"
#include "tool/render_system_factory.hpp"

namespace primaldawn {
    /**
    * 1. 平台层
    * 2. 渲染系统
    * 3. 渲染器
    */
    Engine::Engine(EngineConfig config)
      : engine_config_(config) {
        logging::Init();
        LOGI("Engine initializing...")
        platform_ = PlatformFactory::CreatePlatform(engine_config_.platform_config);
        render_system_ = RenderSystemFactory::CreateRenderSystem(engine_config_.render_system_config);
        //renderer_ = RendererFactory::CreateRenderer(engine_config_.renderer_config);
        LOGI("Engine initialized")
    }

    Engine::~Engine() {
        // 注意逆向于构造顺序
        renderer_.reset();
        render_system_.reset();
        platform_.reset();
    }

    std::unique_ptr<Engine> Engine::Create(EngineConfig config) {
        try {
            return std::unique_ptr<Engine>(new Engine(std::move(config)));
        }
        catch (const std::exception& e) {
            LOGE("Engine creation failed: {}", e.what());
            return nullptr;
        }
    }

    void Engine::ShutDown() {
        is_running_ = false;
    }

    void Engine::AddView(std::unique_ptr<View> view) {
        if (view) {
            views_.push_back(std::move(view));
        }
    }

    void Engine::Run() {
        is_running_ = true;
    }
} // namespace primaldawn
