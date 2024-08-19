/*
    网格数据,包含一个或多个网格部件(MeshPart)
*/
#pragma once

#include <vector>
#include "resource.hpp"
#include "mesh_part.hpp"

namespace PrimalDawn {
    class Mesh : public Resource {
    public:
        typedef std::vector<MeshPart*> MeshPartList;
    private:
        // 一个mesh持有多个mesh元素，用于支持mesh中不同材质的情况
        MeshPartList mMeshPartList;
    public:
        Mesh();
        ~Mesh();
        size_t getMeshPartsSize() const {
            return mMeshPartList.size();
        }

        MeshPart* getMeshPart(size_t index) const {
            return mMeshPartList[index];
        }
    };
}