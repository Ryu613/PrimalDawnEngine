#pragma once

#include "primaldawn/config.hpp"

#include "impl/platform.hpp"

namespace primaldawn {
	class PlatformWindows : public PdPlatform {
	public:
		PlatformWindows(config::Platform config);
		~PlatformWindows();
	};
} // namespace primaldawn
