/*
    通用节点定义(树)
*/
#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace PrimalDawn {
    class Node {
    public:
        // 子节点集合
        typedef std::vector<Node*> ChildNodes;
    protected:
        // 父节点
        Node* mParent;
        // 子节点的集合
        ChildNodes mChildren;
        // 节点的名字
        std::string mName;
        // 朝向(相对于父节点)
        glm::quat mOrientation;
        // 位置(相对于父节点)
        glm::vec3 mPosition;
        // 缩放
        glm::vec3 mScale;
    public:
        Node() = default;
        Node(const std::string& name);
        virtual ~Node();
        const std::string& getName() const {
            return mName;
        }

        Node* getParent() const {
            return mParent;
        }

        const glm::quat& getOrientation() const {
            return mOrientation;
        }

        void setOrientation(const glm::quat& q);

        void setPosition(const glm::vec3& pos);

        const glm::vec3& getPosition() const {
            return mPosition;
        }

        void setScale(const glm::vec3& scale);

        const glm::vec3& getScale() const {
            return mScale;
        }

        void addChild(Node* child);
    };
}