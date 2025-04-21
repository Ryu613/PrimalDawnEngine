#pragma once

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class RenderSystemVulkan;
	class VulkanSwapchain;
	class VulkanContext;
	class RenderFrame;
	/**
	* @brief 负责管理渲染相关的上下文数据
	*/
	class RenderContext {
	public:
		explicit RenderContext(const RenderSystemVulkan& render_system_vulkan);
		virtual ~RenderContext() = default;

		const VulkanContext* GetVulkanContext() const;
		const VulkanSwapchain* GetVulkanSwapchain() const;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		std::unique_ptr<VulkanSwapchain> swapchain_;
		std::vector<std::unique_ptr<RenderFrame>> frames_;
	public:
		// no move, no copy
		RenderContext(const RenderContext&) = delete;
		RenderContext& operator=(const RenderContext&) = delete;
		RenderContext(const RenderContext&&) = delete;
		RenderContext& operator=(RenderContext&&) = delete;
	};
} // namespace primaldawn
