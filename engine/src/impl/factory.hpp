#pragma once

#include <memory>

#include "primaldawn/config.hpp"
#include "primaldawn/platform.hpp"

#include "impl/Platform.hpp"
#include "impl/render_system.hpp"

namespace primaldawn::factory {

	std::unique_ptr<PdPlatform> CreatePlatform(config::Platform platformConfig);

	std::unique_ptr<PdRenderSystem> CreateRenderSystem(config::RenderSystem config);

} // namespace primaldawn::factory
