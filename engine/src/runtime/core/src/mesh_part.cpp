#include "mesh_part.hpp"

namespace PrimalDawn {
    MeshPart::MeshPart() {
        mMaterial = std::make_shared<Material>();
    }
    MeshPart::~MeshPart() {

    }
    void MeshPart::setMaterial(const Material* material) {

    }
    const Material* MeshPart::getMaterial() {
        return mMaterial.get();
    }
}