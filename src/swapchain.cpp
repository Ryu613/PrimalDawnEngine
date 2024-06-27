#include "engine/swapchain.hpp"
#include "engine/context.hpp"

namespace engine {
    Swapchain::Swapchain(int w, int h) {
        queryInfo(w, h);
        vk::SwapchainCreateInfoKHR createInfo;
        // �Ƿ����ͼƬ(��ͼƬ������Ļ��Сʱ)
        createInfo.setClipped(true)
            // �м�������㣨������1��
            // ��vk��image������������ʽ�洢������ж�layer����ָÿ��image��Ϊһ������Ԫ�ط���һ����������У����ƶ�ά���飩
            .setImageArrayLayers(1)
            .setImageUsage(vk::ImageUsageFlagBits::eColorAttachment)
            // ͼ���GPU������Ļʱ������ڻ���ɫ
            .setCompositeAlpha(vk::CompositeAlphaFlagBitsKHR::eOpaque)
            .setSurface(Context::GetInstance().surface)
            .setImageColorSpace(info.format.colorSpace)
            .setImageFormat(info.format.format)
            .setImageExtent(info.imageExtent)
            .setMinImageCount(info.imageCount)
            .setPresentMode(info.present);
        auto& queueIndices = Context::GetInstance().queueFamilyIndices;
        // ��ͼ���������ֶ������ڵ�������о���ͬһ����ָ��ͼ��Ӧ�����ʹ��
        if (queueIndices.graphicsQueue.value() == queueIndices.presentQueue.value()) {
            createInfo.setQueueFamilyIndices(queueIndices.graphicsQueue.value())
                // exclusive:�ų⣺ͬʱֻ�ܱ�һ������ʹ��
                .setImageSharingMode(vk::SharingMode::eExclusive);
       
        }
        // �������������
        else {
            std::array indices = {queueIndices.graphicsQueue.value(), queueIndices.presentQueue.value()};
            createInfo.setQueueFamilyIndices(indices)
                // ��ͬʱʹ��
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
        // ��ɫ�ռ�͸�ʽ
        auto formats = physicalDevice.getSurfaceFormatsKHR(surface);
        info.format = formats[0];
        for (const auto& format : formats) {
            if (format.format == vk::Format::eR8G8B8A8Srgb && format.colorSpace == vk::ColorSpaceKHR::eSrgbNonlinear) {
                info.format = format;
                break;
            }
        }

        auto capabilities = physicalDevice.getSurfaceCapabilitiesKHR(surface);
        // �������ڣ�����max�ķ���max��С��min�ķ���min
        info.imageCount = std::clamp<uint32_t>(2, capabilities.minImageCount, capabilities.maxImageCount);
        info.imageExtent.width = std::clamp<uint32_t>(w, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
        info.imageExtent.height = std::clamp<uint32_t>(h, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

        info.transform = capabilities.currentTransform;

        auto presents = physicalDevice.getSurfacePresentModesKHR(surface);
        // ����ͼ���������Ļ�ϵ�ģʽ��fifo��ʾ���Ƶ�ͼ����ʾʱ�����ƹ����ųɶ��У��Ƚ��ȳ�����
        // fiforelaxted:����һ��ͼû�����굫��һ��ͼ�Ѿ������꣬��ֱ�ӳ��ֻ�����ģ���������ǰ��û������ģ�����ͼ����δ�������������е�������һ��ͼ�ĳ��������ܵ���ͼ��˺��
        // immediate:˭�Ȼ�����չʾ˭��û�ж���
        // mailbox: �������ڻ��Ƶ�ͼ���⣬����һ�����µĴ�����ͼ�����ڻ��Ƶ�ͼ������Ժ�ȡ��������ͼ��
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
            // ��ɫӳ��
            vk::ComponentMapping mapping;
            // ָ��mipmap level�� 0����ͼƬ����
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