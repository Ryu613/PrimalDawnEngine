#include "platform/render_system/vulkan/vulkan_image.hpp"

#include "vulkan/vk_enum_string_helper.h"
#include <tuple>

#include "primaldawn/logging.hpp"
#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"
#include "platform/render_system/vulkan/vulkan_image_view.hpp"


namespace primaldawn {
namespace {
    inline vk::ImageType chooseImageType(const vk::Extent3D& extent) {
        uint32_t dimension_count = !!extent.width + !!extent.height + (1 < extent.depth);
        switch (dimension_count) {
        case 1:
            return vk::ImageType::e1D;
        case 2:
            return vk::ImageType::e2D;
        case 3:
            return vk::ImageType::e3D;
        default:
            throw std::runtime_error("no image type found");
            return vk::ImageType();
        }
    }
} // namespace

    VulkanImage::VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::ImageCreateInfo& create_info)
      : render_system_vulkan_(render_system_vulkan),
        create_info_(create_info) {
        subresource_.mipLevel = 1;
        subresource_.arrayLayer = 1;
        allocateImage();
    }

    VulkanImage::VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::Image& image, const SwapchainProps& swapchain_props)
      : render_system_vulkan_(render_system_vulkan),
        image_(image) {
        create_info_.samples = vk::SampleCountFlagBits::e1;
        create_info_.format = swapchain_props.surface_format.format;
        create_info_.extent = vk::Extent3D{ swapchain_props.extent, 1 };
        create_info_.imageType = chooseImageType(create_info_.extent);
        create_info_.arrayLayers = 1;
        create_info_.mipLevels = 1;

        subresource_.mipLevel = 1;
        subresource_.arrayLayer = 1;
    }

    VulkanImage::~VulkanImage() {
        if (image_) {
            vmaDestroyImage(
                render_system_vulkan_.GetMemoryAllocator(),
                static_cast<VkImage>(image_),
                allocation_
            );
        }
    }

    VulkanImage::VulkanImage(VulkanImage&& other) noexcept
        : render_system_vulkan_(other.render_system_vulkan_),
          image_(std::exchange(other.image_, {})),
          allocation_create_info_(std::exchange(other.allocation_create_info_, {})),
          allocation_(std::exchange(other.allocation_, {})),
          create_info_(std::exchange(other.create_info_, {})),
          subresource_(std::exchange(other.subresource_, {})),
          image_views_(std::exchange(other.image_views_, {})) {
        for (auto& view : image_views_) {
            view->SetImage(*this);
        }
    }

    const vk::Image& VulkanImage::GetImage() const {
        return image_;
    }

    std::unordered_set<VulkanImageView*>& VulkanImage::GetImageViews() {
        return image_views_;
    }

    const vk::ImageCreateInfo& VulkanImage::GetCreateInfo() const {
        return create_info_;
    }

    const vk::ImageSubresource& VulkanImage::GetSubresource() const {
        return subresource_;
    }

    void VulkanImage::allocateImage() {
        if (image_) {
            LOGE("this image has been allocated !");
            return;
        }
        VmaAllocationCreateInfo alloc_create_info{
            .usage = VMA_MEMORY_USAGE_AUTO,
        };
        VmaAllocationInfo alloc_info;
        VkResult result = vmaCreateImage(
            render_system_vulkan_.GetMemoryAllocator(),
            reinterpret_cast<VkImageCreateInfo*>(&create_info_),
            &alloc_create_info,
            reinterpret_cast<VkImage*>(&image_),
            &allocation_,
            &alloc_info
        );
        if (result != VK_SUCCESS) {
            LOGE("VMA allocate image failed!\n{}", string_VkResult(result));
            throw std::runtime_error("vma allocate image failed!");
        }
    }
}
