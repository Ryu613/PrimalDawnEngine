#pragma once

#include <memory>

#include "primaldawn/platform.hpp"
#include "primaldawn/config.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class WindowSystem;
	class PdPlatform : public Platform {
	public:
		~PdPlatform();
	protected:
		explicit PdPlatform(config::Platform config);
	private:
		config::Platform platform_config_;
		std::unique_ptr<WindowSystem> window_system_;
	};

	DOWNCAST(Platform);
} // namespace primaldawn
