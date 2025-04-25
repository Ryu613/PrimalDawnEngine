#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
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

		const RenderSystemVulkan& GetRenderSystem() const;
		const VulkanContext& GetVulkanContext() const;
		const vk::Format& GetDepthFormat() const;
		const VulkanSwapchain& GetVulkanSwapchain() const;
		const std::vector<std::unique_ptr<RenderFrame>>& GetRenderFrames() const;
		const vk::Format& GetFormat() const;
		const vk::Extent2D& GetSurfaceExtent() const;
		const VmaAllocator& GetMemoryAllocator() const;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		std::unique_ptr<VulkanSwapchain> swapchain_;
		std::vector<std::unique_ptr<RenderFrame>> frames_;
	public:
		// no move, no copy
		RenderContext(const RenderContext&) = delete;
		RenderContext& operator=(const RenderContext&) = delete;
		RenderContext(RenderContext&&) = delete;
		RenderContext& operator=(RenderContext&&) = delete;
	};
} // namespace primaldawn
