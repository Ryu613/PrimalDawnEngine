#pragma once

#include <vector>

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class RenderSystemVulkan;
	class VulkanImageBundle;

	struct SwapchainProps {
		vk::SwapchainKHR old_swapchain{ nullptr };
		uint32_t image_count = 3U;
		vk::Extent2D extent;
		vk::SurfaceFormatKHR surface_format;
		uint32_t array_layers;
		vk::ImageUsageFlags image_usage_flags;
		vk::SurfaceTransformFlagBitsKHR pre_transform = vk::SurfaceTransformFlagBitsKHR::eIdentity;
		vk::CompositeAlphaFlagBitsKHR composite_alpha = vk::CompositeAlphaFlagBitsKHR::eInherit;
		vk::PresentModeKHR present_mode;
	};
	struct ImageBundle {
		vk::Image image;
		std::vector<vk::ImageView> image_views;
	};
	class VulkanSwapchain {
	public:
		explicit VulkanSwapchain(const RenderSystemVulkan& render_system_vulkan);
		~VulkanSwapchain();

		const vk::Extent2D& GetExtent() const;
		const SwapchainProps& GetProps() const;
		const std::vector<ImageBundle>& GetImageBundle() const;
		const RenderSystemVulkan& getRenderSystemVulkan() const;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		SwapchainProps props_;
		vk::SwapchainKHR swapchain_;
		std::vector<ImageBundle> image_bundle_;
	public:
		VulkanSwapchain(const VulkanSwapchain&) = delete;
		VulkanSwapchain& operator=(const VulkanSwapchain&) = delete;
		VulkanSwapchain(VulkanSwapchain&&) = delete;
		VulkanSwapchain& operator=(VulkanSwapchain&&) = delete;
	};
} // namespace primaldawn
