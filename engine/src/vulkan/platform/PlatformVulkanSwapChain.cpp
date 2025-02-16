#include "PlatformVulkanSwapChain.h"
#include "VulkanContext.h"

namespace pd {
    PlatformVulkanSwapChain::PlatformVulkanSwapChain(Engine& engine, VulkanContext* ctx) :
        SwapChain(engine),
        mExtent(*(ctx->mExtent2D)),
        mFormat(vk::Format::eR8G8B8A8Unorm){
        vk::PhysicalDevice& phyDevice = *ctx->mPhysicalDevice;
        vk::SurfaceKHR& surface = *ctx->mSurface;
        vk::SurfaceCapabilitiesKHR surfaceProp = phyDevice.getSurfaceCapabilitiesKHR(surface);
        const unsigned int numImages = std::clamp(
            surfaceProp.minImageCount + 1,
            surfaceProp.minImageCount,
            surfaceProp.maxImageCount
        );
        // 界面变换方式
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
        //TODO old_swapchain
        // swapchain images
        // semaphre & fence
    }

    PlatformVulkanSwapChain::~PlatformVulkanSwapChain() {

    }
}
