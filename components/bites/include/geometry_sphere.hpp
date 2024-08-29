#pragma once

#include "bites_prequisites.hpp"
#include "vertex_data.hpp"

namespace PrimalDawnBites {
	class GeometrySphere {
	private:
		VertexData mVertexData;
		void init(int prec);
	public:
		GeometrySphere();
		GeometrySphere(int prec);
		~GeometrySphere();
		const VertexData& getVertexData() const {
			return mVertexData;
		}
	};
}