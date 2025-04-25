#pragma once

#include "platform/render_system/vulkan/vulkan_common.hpp"
#include "platform/render_system/vulkan/render_target.hpp"

namespace primaldawn {
	class RenderContext;
	class VulkanImage;
	/**
	* @brief 封装每一帧的数据
	*/
	class RenderFrame {
	public:
		/**
		* @brief 注意VulkanImage必须右值
		*/
		explicit RenderFrame(const RenderContext& render_context, VulkanImage&& swapchain_image);
	private:
		const RenderContext& render_context_;
		std::unique_ptr<RenderTarget> render_target_;
	public:
		RenderFrame(const RenderFrame&) = delete;
		RenderFrame& operator=(const RenderFrame&) = delete;
		RenderFrame(RenderFrame&&) noexcept = delete;
		RenderFrame& operator=(RenderFrame&&) noexcept = delete;
	};
} // namespace primaldawn
