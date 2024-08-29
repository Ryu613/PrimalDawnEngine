#include "geometry_sphere.hpp"
#include "vertex_data_builder.hpp"

namespace PrimalDawnBites {
    GeometrySphere::GeometrySphere() {
        init(24);  // 默认精度为24
    }

    GeometrySphere::GeometrySphere(int prec) {
        init(prec);
    }

    GeometrySphere::~GeometrySphere() {
        // 默认析构函数
    }

    void GeometrySphere::init(int prec) {
        int numVertices = (prec + 1) * (prec + 1);
        int numIndices = 6 * prec * prec;

        std::vector<glm::vec3> vertices(numVertices);
        std::vector<glm::vec3> normals(numVertices);
        std::vector<glm::vec2> texCoords(numVertices);
        std::vector<int> indices(numIndices);

        int vertIndex = 0, index = 0;
        for (int i = 0; i <= prec; ++i) {
            for (int j = 0; j <= prec; ++j) {
                float y = (float)(i * M_PI / prec);
                float x = (float)(j * 2 * M_PI / prec);
                glm::vec3 position(
                    sin(y) * cos(x),
                    cos(y),
                    sin(y) * sin(x)
                );
                glm::vec2 texCoord(
                    (float)j / prec,
                    1.0f - (float)i / prec
                );

                vertices[vertIndex] = position;
                normals[vertIndex] = glm::normalize(position);
                texCoords[vertIndex] = texCoord;

                if (i < prec && j < prec) {
                    indices[index++] = i * (prec + 1) + j;
                    indices[index++] = (i + 1) * (prec + 1) + j;
                    indices[index++] = (i + 1) * (prec + 1) + (j + 1);

                    indices[index++] = i * (prec + 1) + j;
                    indices[index++] = (i + 1) * (prec + 1) + (j + 1);
                    indices[index++] = i * (prec + 1) + (j + 1);
                }
                vertIndex++;
            }
        }

        // 使用 VertexDataBuilder 构建 VertexData
        mVertexData = VertexDataBuilder()
            .setNumVertices(numVertices)
            .setNumIndices(numIndices)
            .setVertices(vertices)
            .setNormals(normals)
            .setTexCoords(texCoords)
            .setIndices(indices)
            .build();
    }
}