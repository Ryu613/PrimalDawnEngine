#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
	class RenderPipeline {
	public:
		explicit RenderPipeline(const RenderSystemVulkan& render_system_vulkan);
		virtual ~RenderPipeline() = default;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
	};
} // namespace primaldawn
