#pragma once

#include <memory>

#include "platform/PlatformEnums.hpp"
#include "platform/Platform.hpp"

namespace pd {
	class Platform;
	class RenderSystem;

	class PlatformFactory {
	public:
		static std::unique_ptr<Platform> createPlatform(PlatformConfig& platformConfig);
	};
}
