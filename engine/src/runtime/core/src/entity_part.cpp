#include "entity_part.hpp"
#include "mesh_part.hpp"

namespace PrimalDawn {
	EntityPart::EntityPart()
		: mMeshPart(0) {

	}

	EntityPart::EntityPart(MeshPart* meshPart) {
		mMeshPart = meshPart;
	}

	EntityPart::~EntityPart() {

	}
}