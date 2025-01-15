#include "core/Scene.h"

namespace pd {
    Scene::Scene(Engine& engine) :
        mEngine(engine) {

    }

    Scene::~Scene() noexcept = default;
}
