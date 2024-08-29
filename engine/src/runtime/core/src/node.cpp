#include "node.hpp"
#include "macro.hpp"

namespace PrimalDawn {

    Node::Node(const String& name)
      : mParent(0),
        mName(name),
        mOrientation(glm::quat(1,0,0,0)),
        mPosition(glm::vec3(0,0,0)),
        mScale(glm::vec3(1,1,1)) {

    }

    Node::~Node() {

    }
    void Node::setOrientation(const glm::quat& q) {
        mOrientation = q;
    }

    void Node::setPosition(const glm::vec3& pos) {
        mPosition = pos;
    }

    void Node::addChild(Node* child) {
        // 若这个子节点已有父节点，则是非正常现象
        if (child->mParent) {
            LOG_ERROR("节点创建失败!此节点已有父节点")
        }
        mChildren.push_back(child);
        child->setParent(this);
    }

    Node* Node::createChild(const String& name) {
        Node* newNode = createChildImpl(name);
        this->addChild(newNode);
        return newNode;
    }
}