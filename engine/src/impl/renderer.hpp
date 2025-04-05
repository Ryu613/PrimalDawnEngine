#pragma once

#include "primaldawn/renderer.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdRenderer : public Renderer {

	};

	DOWNCAST(Renderer);
} // namespace primaldawn
