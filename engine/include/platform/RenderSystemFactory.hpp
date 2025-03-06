#pragma once

#include <memory>

namespace pd {
	class RenderSystem;

	class RenderSystemFactory {
	public:
		static std::unique_ptr<RenderSystem> createRenderSystem(RenderSystemConfig& rsConfig);
	};
}
