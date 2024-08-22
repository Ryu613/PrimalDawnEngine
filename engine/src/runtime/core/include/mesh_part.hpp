/*
    网格部件：与材质（Material）对应
*/
#pragma once
#include "prequisites.hpp"

namespace PrimalDawn {
    class MeshPart {
    public:
        MeshPart();
        ~MeshPart();
        void setMaterial(const Material* material);
        const std::shared_ptr<Material> getMaterial();
    private:
        // 材质
        std::shared_ptr<Material> mMaterial;
    };
}