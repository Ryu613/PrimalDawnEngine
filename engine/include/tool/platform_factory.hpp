#pragma once

#include <memory>

#include "platform/platform.hpp"

namespace primaldawn {

	class PlatformFactory {
	public:
		template <typename PlatformSub>
		static std::unique_ptr<Platform<PlatformSub>> CreatePlatform(PlatformConfig platformConfig);
	};
} // namespace primaldawn
