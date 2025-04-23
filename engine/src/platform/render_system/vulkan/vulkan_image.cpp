#include "platform/render_system/vulkan/vulkan_image.hpp"

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
        render_system_vulkan_.GetMemoryAllocator().destroyImage(image_, allocation_);
    }

    const vk::ImageCreateInfo& VulkanImage::GetCreateInfo() const {
        return create_info_;
    }

    void VulkanImage::allocateImage() {
        if (image_) {
            LOGE("this image has been allocated !");
            return;
        }
        vma::AllocationCreateInfo alloc_create_info;
        alloc_create_info.usage = vma::MemoryUsage::eAuto;
        vma::AllocationInfo alloc_info;
        std::tie(image_, allocation_) = render_system_vulkan_.GetMemoryAllocator().createImage(
            create_info_,
            alloc_create_info,
            alloc_info
        );
    }
}
