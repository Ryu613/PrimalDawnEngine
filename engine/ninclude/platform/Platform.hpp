#pragma once

#include <string>
#include <memory>

#include "PlatformEnums.hpp"

namespace pd {
	class WindowSystem;

	class Platform {
	public:
		struct Config {
			std::string appName{ "default" };
			Backend backend = Backend::VULKAN;
			WSI wsi = WSI::GLFW3;
			bool enableDebug = false;
		};
	protected:
		std::unique_ptr<WindowSystem> mWindowSystem;
	};
}
