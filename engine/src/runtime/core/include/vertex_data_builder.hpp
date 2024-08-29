#pragma once

#include "prequisites.hpp"
#include "vertex_data.hpp"

namespace PrimalDawn {
	class VertexDataBuilder {
	private:
		VertexData mVertexData;

	public:
		// 构造函数初始化
		VertexDataBuilder& setNumVertices(int numVertices) {
			mVertexData.mNumVertices = numVertices;
			return *this;
		}

		VertexDataBuilder& setNumIndices(int numIndices) {
			mVertexData.mNumIndices = numIndices;
			return *this;
		}

		VertexDataBuilder& setIndices(const std::vector<int>& indices) {
			mVertexData.mIndices = indices;
			return *this;
		}

		VertexDataBuilder& setVertices(const std::vector<glm::vec3>& vertices) {
			mVertexData.mVertices = vertices;
			return *this;
		}

		VertexDataBuilder& setTexCoords(const std::vector<glm::vec2>& texCoords) {
			mVertexData.mTexCoords = texCoords;
			return *this;
		}

		VertexDataBuilder& setNormals(const std::vector<glm::vec3>& normals) {
			mVertexData.mNormals = normals;
			return *this;
		}

		// 构建并返回 VertexData 对象
		VertexData build() const {
			return mVertexData;
		}
	};
}