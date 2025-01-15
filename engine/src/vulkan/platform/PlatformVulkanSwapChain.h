#pragma once

#include "platform/VulkanCommon.h"
#include "core/SwapChain.h"

namespace pd {
    class VulkanContext;

    /**
    * @brief vulkan交换链的操作封装
    */
    class PlatformVulkanSwapChain : public SwapChain {
    public:
        PlatformVulkanSwapChain(VulkanContext* ctx);
        ~PlatformVulkanSwapChain();
    private:
        vk::Extent2D mExtent;
        vk::Format mFormat = vk::Format::eUndefined;
        vk::SwapchainKHR mSwapchain;
        std::vector<vk::ImageView> mImageViews;
        std::vector<vk::Framebuffer> mFramebuffers;
    };
}
