#pragma once

#include <memory>
#include "core/RenderSystem.hpp"

namespace pd {
	class RenderSystem;

	class RenderSystemFactory {
	public:
		static std::unique_ptr<RenderSystem> createRenderSystem(RenderSystemConfig& rsConfig);
	};
}
