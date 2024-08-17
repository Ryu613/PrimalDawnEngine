#pragma once

#include <vector>
#include "resource.hpp"
#include "mesh_element.hpp"

namespace PrimalDawn {
    class Mesh : public Resource {
    public:
        typedef std::vector<MeshElement*> meshElemList;
    private:
        // һ��mesh���ж��meshԪ�أ�����֧��mesh�в�ͬ���ʵ����
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