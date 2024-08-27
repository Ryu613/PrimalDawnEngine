#include "primitive_sphere.hpp"
#include "mesh.hpp"

using namespace PrimalDawn;

namespace PrimalDawnBites {
	PrimitiveSphere::PrimitiveSphere() {
	}
	PrimalDawn::Mesh* getPrimitiveMesh() {
		Mesh* mesh = new Mesh();
		return mesh;
	}
}