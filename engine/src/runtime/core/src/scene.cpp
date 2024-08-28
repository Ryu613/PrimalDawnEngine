#include "scene.hpp"
#include "scene_node.hpp"

namespace PrimalDawn {
    Scene::Scene()
        : mSceneName{""} {
    }

    Scene::Scene(String& sceneName) 
        : mSceneName{sceneName} {
    }

    const String& Scene::getName() {
        return mSceneName;
    }

    SceneNode* Scene::getSceneNodeRoot() {
        if (mSceneNodeRoot) {
            return mSceneNodeRoot.get();
        }
        else {
            mSceneNodeRoot = std::make_unique<SceneNode>();
            return mSceneNodeRoot.get();
        }
    }
}