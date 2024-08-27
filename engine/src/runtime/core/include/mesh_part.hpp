/*
    网格部件：与材质（Material）对应
*/
#pragma once
#include "prequisites.hpp"
#include "vertex_data.hpp"
#include "material.hpp"

namespace PrimalDawn {
    class MeshPart {
    private:
        // 材质
        std::shared_ptr<Material> mMaterial;
        // 顶点数据
        std::unique_ptr<VertexData> mVertexData;
    public:
        MeshPart();
        ~MeshPart();
        void setMaterial(const Material* material);
        const Material* getMaterial();
        void setVertexData(const VertexData* vertexData);
        VertexData* getVertexData();

    };
}