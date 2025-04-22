#include "platform/render_system/vulkan/vulkan_image.hpp"

#include "platform/render_system/vulkan/vulkan_image_view.hpp"


namespace primaldawn {
    VulkanImage::VulkanImage(const RenderSystemVulkan& render_system_vulkan, const vk::ImageCreateInfo& create_info)
      : render_system_vulkan_(render_system_vulkan),
        create_info_(create_info) {

    }
}
