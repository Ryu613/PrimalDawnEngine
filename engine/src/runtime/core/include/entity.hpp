/*
    实体：即具体的物体，与一个Mesh关联，下面有一个或多个EntityPart
*/
#pragma once

#include "abstract_object.hpp"

namespace PrimalDawn{
    class Entity : public AbstractObject {
    public:
        typedef std::vector<std::unique_ptr<EntityPart>> EntityPartList;
    private:
        // 实体关联的网格
        std::shared_ptr<Mesh> mMesh;
        // 实体部件的列表
        EntityPartList mEntityPartList;
        // 实体无法直接构造
        Entity();
    public:
        Entity(std::shared_ptr<Mesh> mesh);
        ~Entity();
        Mesh* getMesh();
    };
}