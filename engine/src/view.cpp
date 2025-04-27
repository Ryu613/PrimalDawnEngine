#include "impl/view.hpp"

#include "impl/camera.hpp"
#include "impl/scene.hpp"

namespace primaldawn {
    void View::SetScene(Scene* scene) {
        downcast(this)->SetScene(downcast(scene));
    }

    Scene* View::GetScene() noexcept {
        return downcast(this)->GetScene();
    }

    void View::SetCamera(Camera* camera) noexcept {
        downcast(this)->SetCamera(downcast(camera));
    }

    Camera& View::GetCamera() noexcept {
        return downcast(this)->GetCamera();
    }
} // namespace primaldawn
