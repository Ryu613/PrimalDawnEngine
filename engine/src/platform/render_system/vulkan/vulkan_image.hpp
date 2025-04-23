#pragma once

#include <unordered_set>

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class RenderSystemVulkan;
	class VulkanImageView;
	struct SwapchainProps;
	class VulkanImage {
	public:
		/**
		* @brief construct vk::Image in this constructor
		*/
		explicit VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::ImageCreateInfo& create_info);
		/**
		* @brief construct base on swapchain image & props
		*/
		explicit VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::Image& image, const SwapchainProps& swapchain_props);

		~VulkanImage();

		VulkanImage(VulkanImage&&) noexcept;

		const vk::ImageCreateInfo& GetCreateInfo() const;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		vk::ImageCreateInfo create_info_;
		vk::ImageSubresource subresource_;
		vk::Image image_;
		vma::Allocation allocation_;
		std::unordered_set<VulkanImageView*> views_;

		/**
		* @brief allocate image from vma allocator
		*/
		void allocateImage();
	public:
		// no copy & no operator move, only move construct allowed
		VulkanImage(const VulkanImage&) = delete;
		VulkanImage& operator=(const VulkanImage&) = delete;
		VulkanImage& operator=(VulkanImage&&) noexcept = delete;
	};
} // namespace primaldawn
