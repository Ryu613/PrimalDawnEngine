#include "impl/engine.hpp"

#include "primaldawn/logging.hpp"

#include "ze/ecs/ecs.hpp"

#include "impl/factory.hpp"
#include "impl/render_system.hpp"
#include "impl/platform.hpp"
#include "impl/window_system.hpp"
#include "impl/view.hpp"
#include "impl/renderer.hpp"
#include "impl/scene.hpp"

namespace primaldawn {
    using namespace ze;
    /**
    * 1. platform
    * 2. render system
    * 3. entity manager
    */
    PdEngine::PdEngine(const config::Engine& config)
      : config_(config),
        allocator_("PdEngine") {
        logging::Init();
        LOGI("Engine initializing...")
        platform_ = factory::CreatePlatform(config_.platform);
        render_system_ = factory::CreateRenderSystem(*platform_, config_.render_system);
        ecs::init();
        LOGI("Engine initialized")
    }

    PdEngine::~PdEngine() {
        LOGI("destroying engine...")
        allocator_.destroy(scene_);
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
        scene_ = allocator_.make<PdScene>(*this);
        return p;
    }

    PdView* PdEngine::CreateView() {
        view_ = allocator_.make<PdView>(*this);
        return view_;
    }

    PdRenderer* PdEngine::CreateRenderer() {
        renderer_ = allocator_.make<PdRenderer>(*this);
        return renderer_;
    }

    PdCamera* PdEngine::CreateCamera() {
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
