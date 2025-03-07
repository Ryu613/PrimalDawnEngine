#pragma once

#include "VulkanCommon.hpp"
#include "core/SwapChain.hpp"

namespace pd {
    class VulkanContext;

    /**
    * @brief vulkan交换链的操作封装
    */
    class PlatformVulkanSwapChain : public SwapChain {
    public:
        PlatformVulkanSwapChain(Engine& engine, VulkanContext* ctx);
        ~PlatformVulkanSwapChain();
    private:
        // 用于image的信号量数量： 三重缓冲的话为3乘以最大渲染通道数量(15)
        static constexpr int IMAGE_READY_SEMAPHORE_COUNT = 3 * 15;

        vk::Extent2D mExtent;
        vk::Format mFormat = vk::Format::eUndefined;
        vk::SwapchainKHR mSwapchain;
        std::vector<vk::ImageView> mImageViews;
        std::vector<vk::Framebuffer> mFramebuffers;
        vk::Semaphore mImageReady[IMAGE_READY_SEMAPHORE_COUNT];
    };
}
