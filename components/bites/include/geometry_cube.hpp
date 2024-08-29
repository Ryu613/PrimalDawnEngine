#pragma once

#include "bites_prequisites.hpp"
#include "vertex_data.hpp"

namespace PrimalDawnBites {
	class GeometryCube {
	private:
		VertexData mVertexData;
		void init(float edgeLength);
	public:
		GeometryCube();
		GeometryCube(float edgeLength);
		~GeometryCube() = default;
		const VertexData& getVertexData() const {
			return mVertexData;
		}
	};
}