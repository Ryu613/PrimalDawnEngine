#include "scene.hpp"
#include "scene_node.hpp"

namespace PrimalDawn {
    Scene::Scene()
      : mSceneName(),
        mCurrentViewport(0){
    }

    Scene::Scene(const String& sceneName) 
      : mSceneName(sceneName),
        mCurrentViewport(0){
    }

    Scene::~Scene() {

    }

    const String& Scene::getName() {
        return mSceneName;
    }

    SceneNode* Scene::getSceneNodeRoot() {
        if (!mSceneNodeRoot) {
            mSceneNodeRoot.reset(new SceneNode(this, String("PrimalDawn/SceneRoot")));
        }
        return mSceneNodeRoot.get();
    }

    SceneNode* Scene::createSceneNode() {
        SceneNode* sn = new SceneNode();
        mSceneNodeList.push_back(sn);
        return sn;
    }

    SceneNode* Scene::createSceneNode(Scene* scene, const String& name) {
        SceneNode* sn = new SceneNode(scene, name);
        mSceneNodeList.push_back(sn);
        return sn;
    }
}