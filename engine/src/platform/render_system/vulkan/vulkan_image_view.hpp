#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
	class VulkanImage;
	class VulkanImageView {
	public:
		explicit VulkanImageView(const RenderSystemVulkan& render_system, VulkanImage& image, vk::ImageViewType image_view_type);
		~VulkanImageView();
		VulkanImageView(VulkanImageView&& other) noexcept;

		void SetImage(VulkanImage& image);
	private:
		const RenderSystemVulkan& render_system_vulkan_;
		VulkanImage* image_ = nullptr;
		vk::ImageViewCreateInfo create_info_;
		vk::ImageView image_view_;
	public:
		VulkanImageView(const VulkanImageView&) = delete;
		VulkanImageView& operator=(const VulkanImageView&) = delete;
		VulkanImageView& operator=(VulkanImageView&&) = delete;
	};
} // namespace primaldawn
