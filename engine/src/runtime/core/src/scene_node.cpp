#include "scene_node.hpp"
#include "abstract_object.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "node.hpp"
#include "scene.hpp"

namespace PrimalDawn {
    SceneNode::SceneNode(Scene* scene)
      : Node(),
        mScene(scene){

    }

    SceneNode::SceneNode(Scene* scene, const String& name) 
      : Node(name),
        mScene(scene) {

    }

    SceneNode::~SceneNode() {

    }

    void SceneNode::bindObject(AbstractObject* obj) {
        mObjects.push_back(obj);
    }

    void SceneNode::unbindObject(AbstractObject* obj) {

    }

    SceneNode* SceneNode::createChildSceneNode(const String& name) {
        Node* newNode = this->createChild(name);
        return static_cast<SceneNode*>(newNode);
    }

    Node* SceneNode::createChildImpl() {
        return mScene->createSceneNode();
    }

    Node* SceneNode::createChildImpl(const String& name) {
        return mScene->createSceneNode(mScene, name);
    }

    void Node::setParent(Node* parent) {
        mParent = parent;
    }
}