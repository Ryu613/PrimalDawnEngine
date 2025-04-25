#include "platform/render_system/vulkan/vulkan_image_view.hpp"

#include "vulkan/vulkan_format_traits.hpp"

#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_image.hpp"

namespace primaldawn {
    VulkanImageView::VulkanImageView(const RenderSystemVulkan& render_system, VulkanImage& image, vk::ImageViewType image_view_type)
      : render_system_vulkan_(render_system),
        image_(&image) {
        create_info_.image = image_->GetImage();
        create_info_.viewType = image_view_type;
        create_info_.format = image_->GetCreateInfo().format;
        create_info_.subresourceRange = vk::ImageSubresourceRange(
            (std::string(vk::componentName(create_info_.format, 0)) == "D")
                ? vk::ImageAspectFlagBits::eDepth
                : vk::ImageAspectFlagBits::eColor,
            0,
            image_->GetSubresource().mipLevel,
            0,
            image_->GetSubresource().arrayLayer
        );

        image_view_ = render_system_vulkan_.GetContext().GetLogicalDevice().createImageView(create_info_);
        image_->GetImageViews().emplace(this);
    }

    VulkanImageView::~VulkanImageView() {

    }

    VulkanImageView::VulkanImageView(VulkanImageView&& other) noexcept
      : render_system_vulkan_(other.render_system_vulkan_),
        image_(other.image_),
        create_info_(std::exchange(other.create_info_, {})) {
        auto& views = image_->GetImageViews();
        views.erase(&other);
        views.emplace(this);
        other.image_view_ = vk::ImageView();
    }

    void VulkanImageView::SetImage(VulkanImage& image) {
        image_ = &image;
    }
}
