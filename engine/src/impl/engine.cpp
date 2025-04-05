#include "impl/engine.hpp"

#include "primaldawn/view.hpp"
#include "logging.hpp"

#include "impl/factory.hpp"
#include "impl/render_system.hpp"
#include "impl/platform.hpp"
#include "impl/view.hpp"

namespace primaldawn {
    /**
    * 1. 平台层
    * 2. 渲染系统
    * 3. 渲染器
    */
    PdEngine::PdEngine(config::Engine config)
      : config_(config) {
        logging::Init();
        LOGI("Engine initializing...")
        platform_ = factory::CreatePlatform(config_.platform);
        render_system_ = factory::CreateRenderSystem(config_.render_system);
        //renderer_ = factory::CreateRenderer(engine_config_.renderer_config);
        LOGI("Engine initialized")
    }

    PdEngine::~PdEngine() {
        // 注意逆向于构造顺序
        renderer_.reset();
        render_system_.reset();
        platform_.reset();
    }

    std::unique_ptr<Engine> PdEngine::Create(config::Engine config) {
        return std::unique_ptr<Engine>(new PdEngine(std::move(config)));
    }

    void PdEngine::ShutDown() {
        is_running_ = false;
    }

    void PdEngine::AddView(std::unique_ptr<View> view) {
        if (view) {
            views_.push_back(std::move(view));
        }
    }

    void PdEngine::Run() {
        is_running_ = true;
    }
} // namespace primaldawn
