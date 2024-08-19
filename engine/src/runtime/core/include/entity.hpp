/*
    实体：即具体的物体，与一个Mesh关联，下面有一个或多个EntityPart
*/
#pragma once

#include "abstract_object.hpp"
#include "mesh.hpp"
#include "entity_part.hpp"

namespace PrimalDawn{
    enum ENTITY_TYPE {
        PRIMITIVE_TYPE_CUBE = 1,
        PRIMITIVE_TYPE_SPHERE,
    };
    class Entity : public AbstractObject {
    public:
        typedef std::vector<EntityPart*> EntityPartList;
    private:
        // 实体关联的网格
        std::unique_ptr<Mesh> mMesh;
        // 实体部件的列表
        EntityPartList mEntityPartList;
        // 实体无法直接构造
        Entity();
    public:
        ~Entity();
    };
}