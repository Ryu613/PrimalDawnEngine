#include "engine/render_process.hpp"
#include "engine/shader.hpp"
#include "engine/context.hpp"

namespace engine {
    void RenderProcess::InitPipeline(int width, int height) {
        vk::GraphicsPipelineCreateInfo createInfo;
        // 1. Vertex Input
        vk::PipelineVertexInputStateCreateInfo inputState;
        createInfo.setPVertexInputState(&inputState);
        // 2. Vertex Assembly
        vk::PipelineInputAssemblyStateCreateInfo inputAsm;
        inputAsm.setPrimitiveRestartEnable(false)
            // ���������
            .setTopology(vk::PrimitiveTopology::eTriangleList);

        // 3. Shader
        auto stages = Shader::GetInstance().GetStage();
        createInfo.setStages(stages);

        // 4. viewport
        vk::PipelineViewportStateCreateInfo viewportStateInfo;
        vk::Viewport viewport(0, 0, width, height, -1, 1);
        viewportStateInfo.setViewports(viewport);
        // ������Ļʵ��չʾͼ�������
        vk::Rect2D rect({ 0,0 }, { static_cast<uint32_t>(width), static_cast<uint32_t>(height) });
        viewportStateInfo.setScissors(rect);
        createInfo.setPViewportState(&viewportStateInfo);

        // 5. rasterization
        vk::PipelineRasterizationStateCreateInfo rastInfo;
        // �Ƿ�������դ���Ľ��
        rastInfo.setRasterizerDiscardEnable(false)
            .setCullMode(vk::CullModeFlagBits::eBack)
            .setFrontFace(vk::FrontFace::eCounterClockwise)
            .setPolygonMode(vk::PolygonMode::eFill)
            .setLineWidth(1);
        createInfo.setPRasterizationState(&rastInfo);

        // 6. multisample
        vk::PipelineMultisampleStateCreateInfo multisampleCreateInfo;
        multisampleCreateInfo.setSampleShadingEnable(false)
            // ָ����դ��ʱ��ζԵ���в�����Ĭ��0�����Ե���в���
            .setRasterizationSamples(vk::SampleCountFlagBits::e1);
        createInfo.setPMultisampleState(&multisampleCreateInfo);

        // 7. test - stencil test, depth test

        // 8. color blending(��ɫ�ڻ�)
        vk::PipelineColorBlendStateCreateInfo blendCreateInfo;
        vk::PipelineColorBlendAttachmentState attachs;
        attachs.setBlendEnable(false)
            .setColorWriteMask(vk::ColorComponentFlagBits::eA |
                vk::ColorComponentFlagBits::eB |
                vk::ColorComponentFlagBits::eG |
                vk::ColorComponentFlagBits::eR);
        blendCreateInfo.setLogicOpEnable(false)
            .setAttachments(attachs);
        createInfo.setPColorBlendState(&blendCreateInfo);

        auto result = Context::GetInstance().logicDevice.createGraphicsPipeline(nullptr, createInfo);
        if (result.result != vk::Result::eSuccess) {
            throw std::runtime_error("create pipeline failed");
        }
        pipeline = result.value;

    }

    void RenderProcess::DestroyPipeline() {
        Context::GetInstance().logicDevice.destroyPipeline(pipeline);
    }
}