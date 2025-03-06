#include "core/Scene.hpp"

namespace pd {
    Scene::Scene(Engine& engine) :
        mEngine(engine) {

    }

    Scene::~Scene() noexcept = default;
}
