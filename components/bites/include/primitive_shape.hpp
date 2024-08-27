#pragma once

#include <glm/glm.hpp>
#include "bites_prequisites.hpp"
#include "mesh.hpp"

namespace PrimalDawnBites {

	enum SHAPE_TYPE {
		PRIMITIVE_CUBE = 1,
		PRIMITIVE_SPHERE,
	};
	class PrimitiveShape {
	public:
		typedef std::map<SHAPE_TYPE, std::shared_ptr<Mesh>> PrimitiveMeshes;
	protected:
		PrimitiveMeshes mPrimitiveMeshes;
	public:
		PrimitiveShape();
		PrimitiveShape(String& name);
		Entity* getPrimitiveEntity(enum SHAPE_TYPE shapeType);
	};
}