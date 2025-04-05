#pragma once

#include <memory>

#include "primaldawn/config.hpp"
#include "primaldawn/platform.hpp"

#include "impl/render_system.hpp"

namespace primaldawn::factory {

	std::unique_ptr<Platform> CreatePlatform(config::Platform platformConfig);

	std::unique_ptr<RenderSystem> CreateRenderSystem(config::RenderSystem config);

} // namespace primaldawn::factory
