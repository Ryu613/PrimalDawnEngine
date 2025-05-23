#include "impl/engine.hpp"

#include "primaldawn/logging.hpp"

#include "impl/factory.hpp"
#include "impl/render_system.hpp"
#include "impl/platform.hpp"
#include "impl/window_system.hpp"
#include "impl/view.hpp"
#include "impl/renderer.hpp"
#include "impl/scene.hpp"

namespace primaldawn {
    /**
    * 1. platform
    * 2. render system
    * 3. entity manager
    */
    PdEngine::PdEngine(const config::Engine& config)
      : config_(config) {
        logging::Init();
        LOGI("Engine initializing...")
        platform_ = factory::CreatePlatform(config_.platform);
        render_system_ = factory::CreateRenderSystem(*platform_, config_.render_system);
        LOGI("Engine initialized")
    }

    PdEngine::~PdEngine() {
        LOGI("destroying engine...")
    }

    PdEngine* PdEngine::Create(const config::Engine& config) {
        return new PdEngine(config);
    }

    void PdEngine::Destroy(PdEngine* engine) {
        if (engine) {
            engine->shutdown();
            delete engine;
        }
    }

    PdScene* PdEngine::CreateScene() {
        //scene_ = std::make_unique<PdScene>();
        //return scene_.get();
        return nullptr;
    }

    void PdEngine::Run() {
        is_running_ = true;
    }

    void PdEngine::shutdown() {
        LOGI("engine is shutting down")
        is_running_ = false;
    }
} // namespace primaldawn
