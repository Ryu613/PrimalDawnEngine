/*
    场景节点(用于生成scene graph)
*/

#pragma once
#include "node.hpp"

namespace PrimalDawn {
    class SceneNode : public Node {
    private:
        Node* createChildImpl() override;

        Node* createChildImpl(const String& name) override;
    public:
        typedef std::vector<AbstractObject*> ObjectList;
    protected:
        ObjectList mObjects;
        // 节点所属的场景
        Scene* mScene;
    public:
        SceneNode() = default;
        SceneNode(Scene* scene);
        SceneNode(Scene* scene, const String& name);
        ~SceneNode();
        // 绑定物体
        virtual void bindObject(AbstractObject* obj);
        // 解绑物体
        virtual void unbindObject(AbstractObject* obj);
        // 创建子场景节点
        virtual SceneNode* createChildSceneNode(const String& name);
    };
}