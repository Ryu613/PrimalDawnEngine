#pragma once

#include <memory>

#include "primaldawn/config.hpp"
#include "impl/platform.hpp"
#include "impl/render_system.hpp"

namespace primaldawn::factory {

	static std::unique_ptr<Platform> CreatePlatform(config::Platform platformConfig);

	static std::unique_ptr<RenderSystem> CreateRenderSystem(config::RenderSystem config);

} // namespace primaldawn::factory
