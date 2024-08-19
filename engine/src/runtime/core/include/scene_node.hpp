/*
    �����ڵ�(��������scene graph)
*/

#pragma once

#include "node.hpp"
#include "abstract_object.hpp"

namespace PrimalDawn {
    class SceneNode : public Node {
    public:
        typedef std::vector<AbstractObject*> ObjList;
    protected:
        ObjList mObjects;
    public:
        SceneNode();
        SceneNode(std::string& name);
        ~SceneNode();
        // ������
        virtual void bindObject(AbstractObject* obj);
        // �������
        virtual void unbindObject(AbstractObject* obj);
    };
}