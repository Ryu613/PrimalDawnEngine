/*
    �����ڵ�(��������scene graph)
*/

#pragma once

#include "prequisites.hpp"
#include "node.hpp"

namespace PrimalDawn {
    class SceneNode : public Node {
    public:
        typedef std::vector<AbstractObject*> ObjList;
    protected:
        ObjList mObjects;
    public:
        SceneNode();
        ~SceneNode();
        // ������
        virtual void bindObject(AbstractObject* obj);
        // �������
        virtual void unbindObject(AbstractObject* obj);
        // �����ӳ����ڵ�
        virtual SceneNode* createChildSceneNode(const String& name);
    };
}