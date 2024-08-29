#include "mesh.hpp"
#include "mesh_part.hpp"

namespace PrimalDawn {
	Mesh::Mesh() {
		mMeshPartList.push_back(std::make_unique<MeshPart>());
	}

	Mesh::~Mesh() {

	}
}