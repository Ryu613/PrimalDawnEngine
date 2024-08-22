#include "scene.hpp"

namespace PrimalDawn {
    Scene::Scene() {
    }

    String& Scene::getName() {
        return mSceneName;
    }

    SceneNode* Scene::getSceneNodeRoot() {
        return nullptr;
    }
}