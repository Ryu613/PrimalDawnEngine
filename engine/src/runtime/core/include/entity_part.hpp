/*
    实体的一部分(用于支持一个物体多种材质)
*/
#pragma once

#include "prequisites.hpp"
#include "mesh_part.hpp"

namespace PrimalDawn {
    class EntityPart {
    private:
        MeshPart* mMeshPart;
    public:
        EntityPart();
        EntityPart(MeshPart* meshPart);
        ~EntityPart();
    };
}