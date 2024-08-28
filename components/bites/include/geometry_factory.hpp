#pragma once

#include "bites_prequisites.hpp"

namespace PrimalDawnBites {
	class GeometryFactory {
	public:
		GeometryFactory();
		~GeometryFactory();
		static VertexData createCube();
		static VertexData createSphere();
	};
}