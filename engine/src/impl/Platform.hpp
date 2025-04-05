#pragma once

#include "primaldawn/platform.hpp"

#include "primaldawn/config.hpp"

namespace primaldawn {
	class WindowSystem;
	class PdPlatform : public Platform {
	private:
		config::Platform platform_config_;
		std::unique_ptr<WindowSystem> window_system_;
	};
} // namespace primaldawn
