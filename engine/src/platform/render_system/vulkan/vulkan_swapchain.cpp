#include "platform/render_system/vulkan/vulkan_swapchain.hpp"

#include <algorithm>
#include <vector>

#include "impl/platform.hpp"
#include "impl/window_system.hpp"
#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"

namespace primaldawn {
namespace {
    const std::vector<vk::SurfaceFormatKHR> desired_surface_format = {
        {vk::Format::eR8G8B8A8Srgb, vk::ColorSpaceKHR::eSrgbNonlinear},
        {vk::Format::eB8G8R8A8Srgb, vk::ColorSpaceKHR::eSrgbNonlinear}
    };
    const vk::SurfaceTransformFlagBitsKHR transform = vk::SurfaceTransformFlagBitsKHR::eIdentity;
}
    VulkanSwapchain::VulkanSwapchain(const RenderSystemVulkan& render_system_vulkan)
        : render_system_vulkan_(render_system_vulkan) {
        auto& physical_device = render_system_vulkan_.GetContext()->GetPhysicalDevice();
        auto& device = render_system_vulkan_.GetContext()->GetLogicalDevice();
        auto& surface = render_system_vulkan_.GetSurface();
        auto old_swapchain = swapchain_;
        const vk::SurfaceCapabilitiesKHR surface_caps = physical_device.getSurfaceCapabilitiesKHR(surface);
        if (old_swapchain) {
            props_.old_swapchain = swapchain_;
            for (auto& each_image : image_bundle_) {
                device.destroyImage(each_image.image);
                for (auto& each_image_view : each_image.image_views) {
                    device.destroyImageView(each_image_view);
                }
                each_image.image_views.clear();
            }
        }
        uint32_t desired_image_count = surface_caps.minImageCount + 1;
        if (surface_caps.maxImageCount > 0 && desired_image_count > surface_caps.maxImageCount) {
            desired_image_count = surface_caps.maxImageCount;
        }
        props_.image_count = desired_image_count;
        auto& window_config = render_system_vulkan_.GetPlatform()->GetWindowSystem()->GetConfig();

        if (surface_caps.currentExtent.width == INVALID_VK_INDEX) {
            props_.extent.width = window_config.extent.width;
            props_.extent.height = window_config.extent.height;
        }
        else {
            props_.extent.width = std::clamp(
                window_config.extent.width,
                surface_caps.minImageExtent.width,
                surface_caps.maxImageExtent.width
            );
            props_.extent.height = std::clamp(
                window_config.extent.height,
                surface_caps.minImageExtent.height,
                surface_caps.maxImageExtent.height
            );
        }
        std::vector<vk::SurfaceFormatKHR> surface_formats = physical_device.getSurfaceFormatsKHR(surface);
        bool find_format = false;
        for (auto& each_format : surface_formats) {
            for (auto& each_desired_format : desired_surface_format) {
                if (each_desired_format.format == each_format.format) {
                    props_.surface_format = each_desired_format;
                    find_format = true;
                    break;
                }
            }
            if (find_format) {
                break;
            }
        }
        if (!find_format) {
            throw std::runtime_error("surface format not supported!");
        }
        props_.array_layers = 1;
        props_.image_usage_flags = vk::ImageUsageFlagBits::eColorAttachment
            | vk::ImageUsageFlagBits::eTransferDst
            | vk::ImageUsageFlagBits::eTransferSrc;
        props_.pre_transform = transform;
        const vk::CompositeAlphaFlagBitsKHR composite_alpha =
            (surface_caps.supportedCompositeAlpha & vk::CompositeAlphaFlagBitsKHR::eInherit)
            ? vk::CompositeAlphaFlagBitsKHR::eInherit
            : vk::CompositeAlphaFlagBitsKHR::eOpaque;
        props_.composite_alpha = composite_alpha;
        // window vsync change this value??
        props_.present_mode = vk::PresentModeKHR::eFifo;

        // create swapchain
        const vk::SwapchainCreateInfoKHR create_info(
            {},
            surface,
            props_.image_count,
            props_.surface_format.format,
            props_.surface_format.colorSpace,
            props_.extent,
            props_.array_layers,
            props_.image_usage_flags,
            {},
            {},
            props_.pre_transform,
            props_.composite_alpha,
            props_.present_mode,
            {},
            props_.old_swapchain
        );
        swapchain_ = device.createSwapchainKHR(create_info);
        images_ = device.getSwapchainImagesKHR(swapchain_);
    }

    VulkanSwapchain::~VulkanSwapchain() {
        if (swapchain_) {
            render_system_vulkan_.GetContext()->GetLogicalDevice().destroySwapchainKHR(swapchain_);
        }
    }

    const vk::Extent2D& VulkanSwapchain::GetExtent() const {
        return props_.extent;
    }

    const SwapchainProps& VulkanSwapchain::GetProps() const {
        return props_;
    }

    const std::vector<vk::Image>& VulkanSwapchain::GetImages() const {
        return images_;
    }

    const RenderSystemVulkan& VulkanSwapchain::getRenderSystemVulkan() const {
        return render_system_vulkan_;
    }
} // namespace primaldawn
