#pragma once

#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class VulkanImage;
	class VulkanImageView {
	public:
		explicit VulkanImageView(const VulkanImage& image, vk::ImageViewType image_view_type);
		~VulkanImageView();
	private:
		VulkanImage* image_ = nullptr;
		vk::ImageViewCreateInfo create_info_;
	};
} // namespace primaldawn
