#include "impl/engine.hpp"

#include "impl/scene.hpp"

namespace primaldawn {

    Engine* Engine::Create(const config::Engine* config) noexcept {
        if (!config) {
            config::Engine default_config;
            config = &default_config;
        }
        return PdEngine::Create(*config);
    }

    void Engine::Destroy(Engine* engine) {
        return PdEngine::Destroy(downcast(engine));
    }

    void Engine::Run() {
        return downcast(this)->Run();
    }

    Scene* Engine::CreateScene() noexcept {
        return downcast(this)->CreateScene();
    }

    View* Engine::CreateView() noexcept {
        return nullptr;
    }

    Camera* Engine::CreateCamera() noexcept {
        return nullptr;
    }

    bool Engine::IsRunning() const {
        return downcast(this)->IsRunning();
    }
}
