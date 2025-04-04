#pragma once

#include <memory>

#include "core/render_system_config.hpp"

namespace primaldawn {
	class RenderSystem;

	class RenderSystemFactory {
	public:
		static std::unique_ptr<RenderSystem> CreateRenderSystem(RenderSystemConfig config);
	};
} // namespace primaldawn
