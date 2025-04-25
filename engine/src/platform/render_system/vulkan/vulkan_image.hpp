#pragma once

#include <unordered_set>

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class RenderSystemVulkan;
	class VulkanImageView;
	struct SwapchainProps;
	/**
	* @brief vulkan image
	* use Vulkan Memory Allocator to create image
	* this resource must be managed, cannot assign(by operator) and copy
	*/
	class VulkanImage {
	public:
		/**
		* @brief construct vk::Image in this constructor
		*/
		explicit VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::ImageCreateInfo& create_info, bool owns_image = true);
		/**
		* @brief construct base on swapchain image & props
		* image created by swapchain is not owned by this object, owns_image flag will be used by destructor
		*/
		explicit VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::Image& image, const SwapchainProps& swapchain_props, bool owns_image = false);

		~VulkanImage();

		VulkanImage(VulkanImage&& other) noexcept;

		const vk::Image& GetImage() const;

		std::unordered_set<VulkanImageView*>& GetImageViews();
		
		const vk::ImageCreateInfo& GetCreateInfo() const;

		const vk::ImageSubresource& GetSubresource() const;
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		vk::ImageCreateInfo create_info_;
		vk::ImageSubresource subresource_;
		vk::Image image_;
		bool owns_image_ = false;
		VmaAllocationCreateInfo allocation_create_info_;
		VmaAllocation allocation_;
		std::unordered_set<VulkanImageView*> image_views_;

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
