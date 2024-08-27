/*
    网格数据,包含一个或多个网格部件(MeshPart)
*/
#pragma once

#include <vector>
#include "resource.hpp"
#include "mesh_part.hpp"

namespace PrimalDawn {
    enum MESH_TYPE {
        PRIMITIVE_CUBE = 1,
        PRIMITIVE_SPHERE,
    };
    class Mesh : public Resource {
    public:
        typedef std::vector<std::unique_ptr<MeshPart>> MeshPartList;
    private:
        // 一个mesh持有多个mesh元素，用于支持mesh中不同材质的情况
        MeshPartList mMeshPartList;
    public:
        Mesh();
        Mesh(MESH_TYPE meshType);
        ~Mesh();
        size_t getMeshPartsSize() const {
            return mMeshPartList.size();
        }

        MeshPart* getMeshPart(size_t index) const {
            return mMeshPartList[index].get();
        }

        const MeshPartList& getMeshPartList() const {
            return mMeshPartList;
        }

        //void addMeshPart(std::unique_ptr<MeshPart> meshPart);
    };
}