#include "geometry_cube.hpp"
#include "vertex_data_builder.hpp"

namespace PrimalDawnBites {
	GeometryCube::GeometryCube() {
		init(1.f);
	}

	GeometryCube::GeometryCube(float edgeLength) {
		init(edgeLength);
	}

	void GeometryCube::init(float edgeLength) {
        // 立方体的顶点坐标
        float halfEdge = edgeLength / 2.0f;

        // 顶点数据
        std::vector<glm::vec3> vertices =  {
            { -halfEdge, -halfEdge, -halfEdge },
            { halfEdge, -halfEdge, -halfEdge },
            { halfEdge,  halfEdge, -halfEdge },
            { -halfEdge,  halfEdge, -halfEdge },
            { -halfEdge, -halfEdge,  halfEdge },
            { halfEdge, -halfEdge,  halfEdge },
            { halfEdge,  halfEdge,  halfEdge },
            { -halfEdge,  halfEdge,  halfEdge }
        };

        // 法线数据（按面分组）
        std::vector<glm::vec3> normals = {
            { 0.0f,  0.0f, -1.0f }, // 前
            { 0.0f,  0.0f,  1.0f }, // 后
            { -1.0f,  0.0f,  0.0f }, // 左
            { 1.0f,  0.0f,  0.0f }, // 右
            { 0.0f, -1.0f,  0.0f }, // 下
            { 0.0f,  1.0f,  0.0f }  // 上
        };

        // 纹理坐标
        std::vector<glm::vec2> texCoords = {
            { 0.0f, 0.0f }, { 1.0f, 0.0f },
            { 1.0f, 1.0f }, { 0.0f, 1.0f },
        };

        // 索引数据（用于绘制立方体的面）
        std::vector<int> indices = {
            0, 1, 2, 2, 3, 0, // 前
            4, 5, 6, 6, 7, 4, // 后
            0, 4, 7, 7, 3, 0, // 左
            1, 5, 6, 6, 2, 1, // 右
            0, 1, 5, 5, 4, 0, // 下
            3, 2, 6, 6, 7, 3  // 上
        };

        mVertexData = VertexDataBuilder()
            .setNumVertices(static_cast<int>(vertices.size()))
            .setNumIndices(static_cast<int>(indices.size()))
            .setVertices(vertices)
            .setIndices(indices)
            .setNormals(normals)
            .setTexCoords(texCoords)
            .build();
	}
}