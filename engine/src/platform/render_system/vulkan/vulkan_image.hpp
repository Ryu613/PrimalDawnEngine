#pragma once

#include <unordered_set>

#include "platform/render_system/vulkan/vulkan_common.hpp"
#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
	class VulkanImageView;
	class VulkanImage {
	public:
		explicit VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::ImageCreateInfo& create_info);
		/**
		* @brief allocate image from vma allocator
		*/
		void AllocateImage();
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		const vk::ImageCreateInfo& create_info_;
		vk::ImageSubresource subresource_;
		vk::Image image_;
		VmaAllocation allocation_ = VK_NULL_HANDLE;
		std::unordered_set<VulkanImageView*> views_;
	};
} // namespace primaldawn
