#pragma once

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class RenderContext;
	class RenderTarget;
	/**
	* @brief 封装每一帧的数据
	*/
	class RenderFrame {
	public:
		explicit RenderFrame(const RenderContext& render_context, vk::Image swapchain_image);
	private:
		const RenderContext& render_context_;
		std::unique_ptr<RenderTarget> render_target_;
	};
} // namespace primaldawn
