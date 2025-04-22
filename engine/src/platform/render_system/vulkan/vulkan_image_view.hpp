#pragma once

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class VulkanImage;
	class VulkanImageView {
	public:
		explicit VulkanImageView(const  vk::ImageViewCreateInfo& create_info);
	private:
		VulkanImage* image_ = nullptr;
		const vk::ImageViewCreateInfo& create_info_;
	};
} // namespace primaldawn
