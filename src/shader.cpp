#include "engine/shader.hpp"
#include "engine/context.hpp"

namespace engine {
    std::unique_ptr<Shader> Shader::instance_ = nullptr;

    void Shader::Init(const std::string& vertexSource, const std::string& fragSource) {
        instance_.reset(new Shader(vertexSource, fragSource));
    }
    void Shader::Quit() {
        instance_.reset();
    }

    std::vector<vk::PipelineShaderStageCreateInfo> Shader::GetStage() {
        return stage_;
    }

    void Shader::initStage() {
        stage_.resize(2);
        stage_[0].setStage(vk::ShaderStageFlagBits::eVertex)
            .setModule(Shader::GetInstance().vertexModule)
            // 指定入口函数
            .setPName("main");
        stage_[1].setStage(vk::ShaderStageFlagBits::eVertex)
            .setModule(Shader::GetInstance().fragmentModule)
            // 指定入口函数
            .setPName("main");
    }

    Shader::Shader(const std::string& vertexSource, const std::string& fragSource) {
        vk::ShaderModuleCreateInfo createInfo;
        createInfo.setCodeSize(vertexSource.size())
            .setPCode((uint32_t*)vertexSource.data());

        vertexModule = Context::GetInstance().logicDevice.createShaderModule(createInfo);
        createInfo.setCodeSize(fragSource.size())
            .setPCode((uint32_t*)fragSource.data());
        fragmentModule = Context::GetInstance().logicDevice.createShaderModule(createInfo);
    }

    Shader::~Shader() {
        auto& device = Context::GetInstance().logicDevice;
        device.destroyShaderModule(vertexModule);
        device.destroyShaderModule(fragmentModule);
    }
}