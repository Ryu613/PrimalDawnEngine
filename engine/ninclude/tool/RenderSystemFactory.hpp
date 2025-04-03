#pragma once

#include <memory>
#include "core/RenderSystem.hpp"

namespace pd {

	class RenderSystemFactory {
	public:
		static std::unique_ptr<RenderSystem> createRenderSystem(RenderSystem::Config rsConfig);
	};
}
