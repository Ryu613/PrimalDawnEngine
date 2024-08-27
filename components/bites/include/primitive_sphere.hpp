#pragma once

#include "primitive_shape.hpp"

namespace PrimalDawnBites {
	class PrimitiveSphere : public PrimitiveShape {
	protected:
		PrimalDawn::String& mShapeName = PrimalDawn::String("Sphere");
	public:
		PrimitiveSphere();
		~PrimitiveSphere();
		PrimalDawn::Mesh* getPrimitiveMesh();
	private:
	};
}
