#include "engine/swapchain.hpp"
#include "engine/context.hpp"

namespace engine {
    Swapchain::Swapchain(int w, int h) {
        queryInfo(w, h);
        vk::SwapchainCreateInfoKHR createInfo;
        // 是否裁切图片(当图片大于屏幕大小时)
        createInfo.setClipped(true)
            // 有几个数组层（这里是1）
            // 在vk中image都是以数组形式存储，如果有多layer就是指每组image作为一个数组元素放在一个大的数组中（类似二维数组）
            .setImageArrayLayers(1)
            .setImageUsage(vk::ImageUsageFlagBits::eColorAttachment)
            // 图像从GPU贴到屏幕时，如何融混颜色
            .setCompositeAlpha(vk::CompositeAlphaFlagBitsKHR::eOpaque)
            .setSurface(Context::GetInstance().surface)
            .setImageColorSpace(info.format.colorSpace)
            .setImageFormat(info.format.format)
            .setImageExtent(info.imageExtent)
            .setMinImageCount(info.imageCount)
            .setPresentMode(info.present);
        auto& queueIndices = Context::GetInstance().queueFamilyIndices;
        // 若图像队列与呈现队列所在的命令队列就是同一个，指定图像应该如何使用
        if (queueIndices.graphicsQueue.value() == queueIndices.presentQueue.value()) {
            createInfo.setQueueFamilyIndices(queueIndices.graphicsQueue.value())
                // exclusive:排斥：同时只能被一个队列使用
                .setImageSharingMode(vk::SharingMode::eExclusive);
       
        }
        // 如果是两个队列
        else {
            std::array indices = {queueIndices.graphicsQueue.value(), queueIndices.presentQueue.value()};
            createInfo.setQueueFamilyIndices(indices)
                // 可同时使用
                .setImageSharingMode(vk::SharingMode::eConcurrent);
        }

        swapchain = Context::GetInstance().logicDevice.createSwapchainKHR(createInfo);

    }
    Swapchain::~Swapchain() {
        for (auto& view : imageViews) {
            Context::GetInstance().logicDevice.destroyImageView(view);
        }
        Context::GetInstance().logicDevice.destroySwapchainKHR(swapchain);
    }

    void Swapchain::queryInfo(int w, int h) {
        auto& physicalDevice = Context::GetInstance().physicalDevice;
        auto& surface = Context::GetInstance().surface;
        // 颜色空间和格式
        auto formats = physicalDevice.getSurfaceFormatsKHR(surface);
        info.format = formats[0];
        for (const auto& format : formats) {
            if (format.format == vk::Format::eR8G8B8A8Srgb && format.colorSpace == vk::ColorSpaceKHR::eSrgbNonlinear) {
                info.format = format;
                break;
            }
        }

        auto capabilities = physicalDevice.getSurfaceCapabilitiesKHR(surface);
        // 闭区间内，大于max的返回max，小于min的返回min
        info.imageCount = std::clamp<uint32_t>(2, capabilities.minImageCount, capabilities.maxImageCount);
        info.imageExtent.width = std::clamp<uint32_t>(w, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
        info.imageExtent.height = std::clamp<uint32_t>(h, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

        info.transform = capabilities.currentTransform;

        auto presents = physicalDevice.getSurfacePresentModesKHR(surface);
        // 决定图像呈现在屏幕上的模式，fifo表示绘制的图像显示时按绘制过程排成队列，先进先出呈现
        // fiforelaxted:若上一张图没绘制完但下一张图已经绘制完，则直接呈现绘制完的，跳过队列前面没绘制完的，若在图像尚未绘制完的情况下切到绘制下一张图的场景，可能导致图像撕裂
        // immediate:谁先绘制完展示谁，没有队列
        // mailbox: 除了正在绘制的图像外，缓存一个最新的待绘制图像，正在绘制的图像完成以后，取这个缓存的图像
        info.present = vk::PresentModeKHR::eFifo;
        for (const auto& present : presents) {
            if (present == vk::PresentModeKHR::eMailbox) {
                info.present = present;
                break;
            }
        }
    }

    void Swapchain::getImages() {
        images = Context::GetInstance().logicDevice.getSwapchainImagesKHR(swapchain);
    }

    void Swapchain::createImageViews() {
        imageViews.resize(images.size());
        for (int i = 0; i < images.size(); i++) {
            vk::ImageViewCreateInfo createInfo;
            // 颜色映射
            vk::ComponentMapping mapping;
            // 指定mipmap level， 0级即图片本身
            vk::ImageSubresourceRange range;
            range.setBaseMipLevel(0)
                .setLevelCount(1)
                .setBaseArrayLayer(0)
                .setLayerCount(1)
                .setAspectMask(vk::ImageAspectFlagBits::eColor);
            createInfo.setImage(images[i])
                .setViewType(vk::ImageViewType::e2D)
                .setComponents(mapping)
                .setFormat(info.format.format)
                .setSubresourceRange(range);
            imageViews[i] = Context::GetInstance().logicDevice.createImageView(createInfo);
        }
    }
}