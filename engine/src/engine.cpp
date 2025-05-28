#include "primaldawn/engine.hpp"

#include "primaldawn/scene.hpp"
#include "impl/engine.hpp"

#include "impl/scene.hpp"
#include "impl/view.hpp"
#include "impl/renderer.hpp"
#include "impl/camera.hpp"

namespace primaldawn {

    Engine* Engine::Create(const config::Engine* config) noexcept {
        return PdEngine::Create(config ? *config : config::Engine{});
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
        return downcast(this)->CreateView();
    }

    Renderer* Engine::CreateRenderer() noexcept {
        return downcast(this)->CreateRenderer();
    }

    Camera* Engine::CreateCamera() noexcept {
        return downcast(this)->CreateCamera();
    }

    bool Engine::IsRunning() const {
        return downcast(this)->IsRunning();
    }
}
