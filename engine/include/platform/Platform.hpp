#pragma once

#include <memory>

#include "platform/platform_config.hpp"

namespace primaldawn {
	class WindowSystem;

	template <class PlatformSub>
	class Platform {
	public:
		inline PlatformConfig getConfig() const {
			return platform_config_;
		}
	private:
		std::unique_ptr<WindowSystem> window_system_;
		PlatformConfig platform_config_;
	};
} // namespace primaldawn
