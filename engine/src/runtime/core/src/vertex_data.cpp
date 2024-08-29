#include "vertex_data.hpp"

namespace PrimalDawn {

	VertexData::~VertexData() {

	}

	int VertexData::getNumVertices() const {
		return mNumVertices;
	}
	int VertexData::getNumIndices() const {
		return mNumIndices;
	}
	std::vector<int> VertexData::getIndices() const {
		return mIndices;
	}
	std::vector<glm::vec3> VertexData::getVertices() const {
		return mVertices;
	}
	std::vector<glm::vec2> VertexData::getTexCoords() const {
		return mTexCoords;
	}
	std::vector<glm::vec3> VertexData::getNormals() const {
		return mNormals;
	}
}