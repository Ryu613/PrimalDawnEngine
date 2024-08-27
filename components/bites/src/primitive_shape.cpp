#include "primitive_shape.hpp"
#include "mesh.hpp"
#include "entity.hpp"

namespace PrimalDawnBites {
	PrimitiveShape::PrimitiveShape() {
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_CUBE] = std::make_shared<Mesh>(MESH_TYPE::PRIMITIVE_CUBE);
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_SPHERE] = std::make_shared<Mesh>(MESH_TYPE::PRIMITIVE_SPHERE);
	}

	Entity* PrimitiveShape::getPrimitiveEntity(enum SHAPE_TYPE shapeType) {
		if (mPrimitiveMeshes.find(shapeType) == mPrimitiveMeshes.end()) {
			return nullptr;
		}
		Entity* nEntity = new Entity(mPrimitiveMeshes[shapeType]);
		return nEntity;
	}
}