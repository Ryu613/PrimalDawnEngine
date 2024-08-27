#pragma once

#include <glm/glm.hpp>

namespace PrimalDawn {
	class VertexData {
	private:
		int mNumVertices;
		int mNumIndices;
		std::vector<int> mIndices;
		std::vector<glm::vec3> mVertices;
		std::vector<glm::vec2> mTexCoords;
		std::vector<glm::vec3> mNormals;
	public:
		int getNumVertices() const;
		int getNumIndices() const;
		std::vector<int> getIndices() const;
		std::vector<glm::vec3> getVertices() const;
		std::vector<glm::vec2> getTexCoords() const;
		std::vector<glm::vec3> getNormals() const;
	};
}