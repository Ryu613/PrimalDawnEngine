#pragma once

#include <memory>

#include "platform/Platform.hpp"

namespace pd {
	class Platform;

	class PlatformFactory {
	public:
		static std::unique_ptr<Platform> createPlatform(Platform::Config platformConfig);
	};
}
