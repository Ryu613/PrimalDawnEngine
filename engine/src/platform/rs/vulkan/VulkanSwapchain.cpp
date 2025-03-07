#include "VulkanSwapChain.hpp"
#include "VulkanContext.hpp"

namespace pd {
    PlatformVulkanSwapChain::PlatformVulkanSwapChain(Engine& engine, VulkanContext* ctx) :
        SwapChain(engine),
        mExtent(*(ctx->mExtent2D)),
        mFormat(vk::Format::eR8G8B8A8Unorm) {
        vk::PhysicalDevice& phyDevice = *ctx->mPhysicalDevice;
        vk::SurfaceKHR& surface = *ctx->mSurface;
        vk::SurfaceCapabilitiesKHR surfaceProp = phyDevice.getSurfaceCapabilitiesKHR(surface);
        const unsigned int numImages = std::clamp(
            surfaceProp.minImageCount + 1,
            surfaceProp.minImageCount,
            surfaceProp.maxImageCount
        );
        // determines the transformation for device display orientation
        vk::SurfaceTransformFlagBitsKHR preTrans =
            (surfaceProp.supportedTransforms & vk::SurfaceTransformFlagBitsKHR::eIdentity) ?
            vk::SurfaceTransformFlagBitsKHR::eIdentity : surfaceProp.currentTransform;
        // CompositeAlpha
        vk::CompositeAlphaFlagBitsKHR compositeAlpha =
            (surfaceProp.supportedCompositeAlpha & vk::CompositeAlphaFlagBitsKHR::eInherit) ?
            vk::CompositeAlphaFlagBitsKHR::eInherit : vk::CompositeAlphaFlagBitsKHR::eOpaque;
        // swapchain create
        vk::SwapchainCreateInfoKHR swapchainCreateInfo;
        swapchainCreateInfo.surface = surface;
        swapchainCreateInfo.minImageCount = numImages;
        swapchainCreateInfo.imageFormat = mFormat;
        swapchainCreateInfo.imageColorSpace = vk::ColorSpaceKHR::eSrgbNonlinear;
        swapchainCreateInfo.imageExtent.width = mExtent.width;
        swapchainCreateInfo.imageExtent.height = mExtent.height;
        swapchainCreateInfo.imageArrayLayers = 1;
        swapchainCreateInfo.imageUsage = vk::ImageUsageFlagBits::eColorAttachment;
        swapchainCreateInfo.imageSharingMode = vk::SharingMode::eExclusive;
        swapchainCreateInfo.preTransform = preTrans;
        swapchainCreateInfo.compositeAlpha = compositeAlpha;
        swapchainCreateInfo.presentMode = vk::PresentModeKHR::eFifo;
        swapchainCreateInfo.clipped = true;
        swapchainCreateInfo.oldSwapchain = mSwapchain;
        // create swapchain
        mSwapchain = ctx->mDevice->createSwapchainKHR(swapchainCreateInfo);
        if (!mSwapchain) {
            throw std::runtime_error("failed to create vulkan swapchain!");
        }
        // TODO: deal with old_swapchain
        // swapchain images
        if (surfaceProp.currentExtent.width == 0xFFFFFFFF || surfaceProp.currentExtent.height == 0xFFFFFFFF) {
            mExtent.width = std::clamp(mExtent.width, surfaceProp.minImageExtent.width, surfaceProp.maxImageExtent.width);
            mExtent.height = std::clamp(mExtent.height, surfaceProp.minImageExtent.height, surfaceProp.maxImageExtent.height);
        }
        else {
            mExtent = surfaceProp.currentExtent;
        }
        // semaphore & fence
        vk::SemaphoreCreateInfo semaphoreCreateInfo;
        for (uint32_t i = 0; i < IMAGE_READY_SEMAPHORE_COUNT; ++i) {
            mImageReady[i] = ctx->mDevice->createSemaphore(semaphoreCreateInfo);
            if (!mImageReady[i]) {
                throw std::runtime_error("failed to create semaphore");
            }
        }
    }
      

    PlatformVulkanSwapChain::~PlatformVulkanSwapChain() {

    }
}
