#pragma once

#include <memory>

namespace primaldawn {
	class RenderSystemVulkan;
	class RenderTarget;
	/**
	* @brief 封装每一帧的数据
	*/
	class RenderFrame {
	public:
		explicit RenderFrame(const RenderSystemVulkan& render_system);
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		std::unique_ptr<RenderTarget> render_target_;
	};
} // namespace primaldawn
