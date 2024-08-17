#pragma once

#include <vector>
#include "resource.hpp"
#include "mesh_element.hpp"

namespace PrimalDawn {
    class Mesh : public Resource {
    public:
        typedef std::vector<MeshElement*> meshElemList;
    private:
        // 一个mesh持有多个mesh元素，用于支持mesh中不同材质的情况
        MeshElemList mMeshElemList;
    public:
        Mesh();
        ~Mesh();
        getMeshElems() const {
            return mMeshElemList.size();
        }

        MeshElement* getMeshElement(size_t index) const {
            return mMeshElemList[index];
        }
    };
}