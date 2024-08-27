#include "material.hpp"

namespace PrimalDawn {
	Material::Material() {
		mRenderMethods.push_back(std::make_unique<RenderMethod>());
	}

	Material::~Material() {

	}

	void Material::setVertexData(VertexData& vertexData) {

	}
}