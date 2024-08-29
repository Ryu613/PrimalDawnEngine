#include "mesh_part.hpp"
#include "mesh.hpp"

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

    void MeshPart::setVertexData(const VertexData& vertexData) {
        mVertexData = std::make_unique<VertexData>(vertexData);
    }
    VertexData* MeshPart::getVertexData() {
        return mVertexData.get();
    }
}