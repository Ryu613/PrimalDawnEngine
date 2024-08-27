#include "scene_node.hpp"
#include "abstract_object.hpp"
#include "camera.hpp"
#include "light.hpp"

namespace PrimalDawn {
    SceneNode::SceneNode() {

    }

    SceneNode::~SceneNode() {

    }

    void SceneNode::bindObject(AbstractObject* obj) {

    }

    void SceneNode::unbindObject(AbstractObject* obj) {

    }

    SceneNode* SceneNode::createChildSceneNode(const String& name) {
        return new SceneNode();
    }
}