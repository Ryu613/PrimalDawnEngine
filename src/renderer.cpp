#include "engine/renderer.hpp"
#include "engine/context.hpp"

namespace engine {
    Renderer::Renderer() {
        initCmdPool();
        allocCmdBuf();
        createSems();
        createFence();
    }

    Renderer::~Renderer() {
        auto& device = Context::GetInstance().logicDevice;
        device.freeCommandBuffers(cmdPool_, cmdBuf_);
        device.destroyCommandPool(cmdPool_);
        device.destroySemaphore(imageAvailable_);
        device.destroySemaphore(imageDrawFinish_);
        device.destroyFence(cmdAvailableFence_);
    }

    void Renderer::initCmdPool() {
        vk::CommandPoolCreateInfo createInfo;
        // 允许command buffer可以进行单独重置清空，若不设置，则command buffer必须统一重置
        createInfo.setFlags(vk::CommandPoolCreateFlagBits::eResetCommandBuffer);
        cmdPool_ = Context::GetInstance().logicDevice.createCommandPool(createInfo);
    }

    void Renderer::allocCmdBuf() {
        vk::CommandBufferAllocateInfo allocInfo;
        allocInfo.setCommandPool(cmdPool_)
            .setCommandBufferCount(1)
            // primary直接传给gpu，second：不能直接执行，必须被其他primary里执行
            .setLevel(vk::CommandBufferLevel::ePrimary);
        cmdBuf_ = Context::GetInstance().logicDevice.allocateCommandBuffers(allocInfo)[0];
    }

    void Renderer::render() {
        auto& device = Context::GetInstance().logicDevice;
        auto& renderProcess = Context::GetInstance().renderProcess;
        auto& swapchain = Context::GetInstance().swapchain;

        auto result = device.acquireNextImageKHR(Context::GetInstance().swapchain->swapchain,
            std::numeric_limits<uint64_t>::max(), imageAvailable_);
        if (result.result != vk::Result::eSuccess) {
            std::cout << "acquire next image failed" << std::endl;
        }

        auto imageIndex = result.value;

        cmdBuf_.reset();

        vk::CommandBufferBeginInfo begin;
        begin.setFlags(vk::CommandBufferUsageFlagBits::eOneTimeSubmit);
        cmdBuf_.begin(begin);
        {
            vk::RenderPassBeginInfo renderPassBegin;
            vk::Rect2D area;
            vk::ClearValue clearValue;
            // 清空后的颜色
            clearValue.setColor(vk::ClearColorValue(std::array<float, 4>{0.1f, 0.1f, 0.1f, 0.1f}));
            area.setOffset({ 0, 0 })
                .setExtent(swapchain->info.imageExtent);
            renderPassBegin.setRenderPass(renderProcess->renderPass)
                .setRenderArea(area)
                .setFramebuffer(swapchain->framebuffers[imageIndex])
                .setClearValues(clearValue);
            cmdBuf_.beginRenderPass(renderPassBegin, {});
            {
                cmdBuf_.bindPipeline(vk::PipelineBindPoint::eGraphics, renderProcess->pipeline);
                cmdBuf_.draw(3, 1, 0, 0);
            }
            cmdBuf_.endRenderPass();
        }
        cmdBuf_.end();

        vk::SubmitInfo submit;
        std::array<vk::PipelineStageFlags, 1> waitStages = { vk::PipelineStageFlagBits::eColorAttachmentOutput };
        submit.setCommandBuffers(cmdBuf_)
            .setWaitSemaphores(imageAvailable_)
            .setWaitDstStageMask(waitStages)
            .setSignalSemaphores(imageDrawFinish_);
        Context::GetInstance().graphicsQueue.submit(submit, cmdAvailableFence_);

        vk::PresentInfoKHR present;
        present.setImageIndices(imageIndex)
            .setSwapchains(swapchain->swapchain)
            .setWaitSemaphores(imageDrawFinish_);
        if (Context::GetInstance().presentQueue.presentKHR(present) != vk::Result::eSuccess) {
            std::cout << "image present failed" << std::endl;
        }
        if (Context::GetInstance().logicDevice.waitForFences(cmdAvailableFence_, true, std::numeric_limits<uint64_t>::max()) != vk::Result::eSuccess) {
            std::cout << "wait for fence failed" << std::endl;
        }

        Context::GetInstance().logicDevice.resetFences(cmdAvailableFence_);
     }

    void Renderer::createSems() {
        vk::SemaphoreCreateInfo createInfo;

        imageAvailable_ = Context::GetInstance().logicDevice.createSemaphore(createInfo);
        imageDrawFinish_ = Context::GetInstance().logicDevice.createSemaphore(createInfo);
    }

    void Renderer::createFence() {
        vk::FenceCreateInfo createInfo;
        cmdAvailableFence_ = Context::GetInstance().logicDevice.createFence(createInfo);
    }
}