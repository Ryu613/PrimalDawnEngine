/*
    ��������,����һ���������񲿼�(MeshPart)
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
        // һ��mesh���ж��meshԪ�أ�����֧��mesh�в�ͬ���ʵ����
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