#pragma once

#include "prequisites.hpp"

namespace PrimalDawn {
	class VertexData {
		friend class VertexDataBuilder;
	private:
		int mNumVertices = 0;
		int mNumIndices = 0;
		std::vector<int> mIndices;
		std::vector<glm::vec3> mVertices;
		std::vector<glm::vec2> mTexCoords;
		std::vector<glm::vec3> mNormals;
	public:
		VertexData() = default;
		VertexData(const VertexData&) = default;
		~VertexData();
		int getNumVertices() const;
		int getNumIndices() const;
		std::vector<int> getIndices() const;
		std::vector<glm::vec3> getVertices() const;
		std::vector<glm::vec2> getTexCoords() const;
		std::vector<glm::vec3> getNormals() const;
	};
}