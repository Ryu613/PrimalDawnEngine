#pragma once

#include <string>

#include "platform/platform_enum.hpp"

namespace primaldawn {
	struct RenderSystemConfig {
        std::string app_name{ "default" };
        std::string engine_name{ "Primal Dawn" };
        OS os = OS::UNKNOWN;
        Backend backend = Backend::UNKWONN;
        bool enable_debug = false;
	};
}
