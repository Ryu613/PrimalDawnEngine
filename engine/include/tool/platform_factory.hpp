#pragma once

#include <memory>

#include "platform/platform_config.hpp"

namespace primaldawn {
	class Platform;

	class PlatformFactory {
	public:
		static std::unique_ptr<Platform> CreatePlatform(PlatformConfig platformConfig);
	};
} // namespace primaldawn
