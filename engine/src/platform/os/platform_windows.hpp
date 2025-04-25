#pragma once

#include "primaldawn/config.hpp"

#include "impl/platform.hpp"

namespace primaldawn {
	class PlatformWindows : public PdPlatform {
	public:
		explicit PlatformWindows(const config::Platform& config);
		~PlatformWindows();
	public:

	};
} // namespace primaldawn
