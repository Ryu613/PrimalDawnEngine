/*
    ���񲿼�������ʣ�Material����Ӧ
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
        // ����
        std::shared_ptr<Material> mMaterial;
    };
}