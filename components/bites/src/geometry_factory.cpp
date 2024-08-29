#include "geometry_factory.hpp"
#include "vertex_data.hpp"
#include "geometry_cube.hpp"
#include "geometry_sphere.hpp"

namespace PrimalDawnBites {
	GeometryFactory::GeometryFactory() {
	}

	GeometryFactory::~GeometryFactory() {
	}


	VertexData GeometryFactory::createCube() {
		std::unique_ptr<GeometryCube> cube = std::make_unique<GeometryCube>();
		return cube->getVertexData();
	}

	VertexData GeometryFactory::createSphere() {
		std::unique_ptr<GeometrySphere> sphere = std::make_unique<GeometrySphere>();
		return sphere->getVertexData();
	}
}