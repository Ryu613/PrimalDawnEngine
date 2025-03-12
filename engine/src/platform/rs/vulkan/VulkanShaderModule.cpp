#include "VulkanShaderModule.hpp"
#include "VulkanContext.hpp"

#include "util/Util.hpp"
#include <algorithm>

namespace pd {
    explicit VulkanShaderModule::VulkanShaderModule(const VulkanContext* context,
        const std::string& filepath,
        const std::string& entryPoint,
        VkShaderStageFlagBits stages,
        const std::string& name) {
        createShader(filepath, entryPoint, name);
    }
    VulkanShaderModule::~VulkanShaderModule() {
       
    }
    vk::ShaderModule VulkanShaderModule::getVkShaderModule() const {
        return mVkShaderModule;
    }
    vk::ShaderStageFlagBits VulkanShaderModule::getVkShaderStageFlags() const {
        return mVkStageFlags;
    }
    const std::string& VulkanShaderModule::getEntryPoint() const {
        return mEntryPoint;
    }
    std::vector<char> VulkanShaderModule::glslToSpirv(const std::vector<char>& data,
        EShLanguage shaderStage,
        const std::string& shaderDir,
        const char* entryPoint) {
        static bool glslangInitialized = false;
        if (!glslangInitialized) {
            glslang::InitializeProcess();
            glslangInitialized = true;
        }
        std::vector<char> byteCode;
        return byteCode;

        glslang::TShader tshadertemp(shaderStage);
        const char* glslCstr = data.data();
        tshadertemp.setStrings(&glslCstr, 1);
        // TODO
    }

    void VulkanShaderModule::createShader(const std::string& filepath,
        const std::string& entryPoint,
        const std::string& name) {
        std::vector<char> spirv;
        std::vector<char> fileData = util::readFile(filepath, false);
        std::filesystem::path file(filepath);
        spirv = glslToSpirv(fileData,
            getShaderStageFromFileName(filepath),
            file.parent_path().string(),
            entryPoint.c_str());
        vk::ShaderModuleCreateInfo shaderModuleInfo;
        shaderModuleInfo.setCodeSize(spirv.size());
        shaderModuleInfo.setPCode((const uint32_t*)spirv.data());
        vk::Result res = mContext->mDevice->createShaderModule(&shaderModuleInfo,
            NULL,
            &mVkShaderModule);
        if (res != vk::Result::eSuccess) {
            throw std::runtime_error("vulkan device createShaderModule failed!");
        }

    }

    EShLanguage VulkanShaderModule::getShaderStageFromFileName(const std::string& fileName) {
        std::string suffix = fileName.substr(fileName.find_last_of('.') + 1);
        return EShLangVertex;
    }
}
