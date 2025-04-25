#pragma once

#include <memory>

#include "primaldawn/config.hpp"
#include "primaldawn/enums.hpp"

#include "impl/Platform.hpp"
#include "impl/render_system.hpp"

namespace primaldawn::factory {
	class PdEngine;

	std::unique_ptr<PdPlatform> CreatePlatform(config::Platform& platformConfig);

	std::unique_ptr<PdRenderSystem> CreateRenderSystem(const PdPlatform& platform, config::RenderSystem& config);

} // namespace primaldawn::factory
