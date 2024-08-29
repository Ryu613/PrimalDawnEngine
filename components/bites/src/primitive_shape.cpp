#include "primitive_shape.hpp"
#include "mesh.hpp"
#include "entity.hpp"
#include "geometry_factory.hpp"

namespace PrimalDawnBites {
	PrimitiveShape::PrimitiveShape() {
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_CUBE] = std::make_shared<Mesh>();
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_SPHERE] = std::make_shared<Mesh>();
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_CUBE]->getMeshPart(0)->setVertexData(GeometryFactory::createCube());
		mPrimitiveMeshes[SHAPE_TYPE::PRIMITIVE_SPHERE]->getMeshPart(0)->setVertexData(GeometryFactory::createSphere());
	}

	std::unique_ptr<Entity> PrimitiveShape::getPrimitiveEntity(enum SHAPE_TYPE shapeType) {
		if (mPrimitiveMeshes.find(shapeType) == mPrimitiveMeshes.end()) {
			return nullptr;
		}
		return std::make_unique<Entity>(mPrimitiveMeshes[shapeType]);
	}
}