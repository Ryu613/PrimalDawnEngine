/*
    场景节点(用于生成scene graph)
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
        ~SceneNode();
        // 绑定物体
        virtual void bindObject(AbstractObject* obj);
        // 解绑物体
        virtual void unbindObject(AbstractObject* obj);
        // 创建子场景节点
        virtual SceneNode* createChildSceneNode(const std::string& name);
    };
}