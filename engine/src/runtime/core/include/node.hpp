/*
    ͨ�ýڵ�ʵ��(��)
*/
#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace PrimalDawn {
    class Node {
    public:
        // �ӽڵ㼯��
        typedef std::vector<Node*> ChildNodes;
    protected:
        // ���ڵ�
        Node* mParent;
        // �ӽڵ�ļ���
        ChildNodes mChildren;
        // �ڵ������
        std::string mName;
        // ����(����ڸ��ڵ�)
        glm::quat mOrientation;
        // λ��(����ڸ��ڵ�)
        glm::vec3 mPosition;
        // ����
        glm::vec3 mScale;
    public:
        Node();
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