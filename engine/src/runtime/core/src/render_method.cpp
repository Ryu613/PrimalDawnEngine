#include "render_method.hpp"

namespace PrimalDawn {
	RenderMethod::RenderMethod() {
		mRenderMethodPasses.push_back(std::make_unique<RenderMethodPass>());
	}

	RenderMethod::~RenderMethod() {

	}
}