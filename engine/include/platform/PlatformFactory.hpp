#pragma once

#include <memory>

#include "platform/PlatformEnums.hpp"

namespace pd {
	class Platform;
	class RenderSystem;

	class PlatformFactory {
	public:
		static std::unique_ptr<Platform> createPlatform(OS os);

		static std::unique_ptr<RenderSystem> createRenderSystem(Backend backend);
	};
}
