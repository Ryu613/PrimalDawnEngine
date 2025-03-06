#pragma once

#include <memory>
#include "platform/PlatformEnums.hpp"

namespace pd {
	class RenderSystem;

	class RenderSystemFactory {
	public:
		static std::unique_ptr<RenderSystem> createRenderSystem(OS os, Backend backend);
	};
}
