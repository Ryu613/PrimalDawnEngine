#include "VulkanContext.hpp"
#include "util/Util.hpp"
#include "GLSLCompiler.hpp"
#include <map>

namespace pd {
    vk::ShaderModule VulkanContext::createShaderModule(const char* filepath) {
        static const std::map<std::string, vk::ShaderStageFlagBits> shaderStageMap = { {"comp", vk::ShaderStageFlagBits::eCompute},
                                                                                    {"frag", vk::ShaderStageFlagBits::eFragment},
                                                                                    {"geom", vk::ShaderStageFlagBits::eGeometry},
                                                                                    {"tesc", vk::ShaderStageFlagBits::eTessellationControl},
                                                                                    {"tese", vk::ShaderStageFlagBits::eTessellationEvaluation},
                                                                                    {"vert", vk::ShaderStageFlagBits::eVertex} };
        auto buffer = util::readFile(filepath, false);
        std::string fileExt = filepath;
        fileExt = fileExt.substr(fileExt.find_last_of(".") + 1);

        std::vector<uint32_t> sirvCode;

        auto stageIt = shaderStageMap.find(fileExt);
        if (stageIt == shaderStageMap.end()) {
            throw std::runtime_error("cannot find Shader file extension: " + fileExt);
        }
        std::vector<uint32_t> spirvCode;
        GLSLCompiler compiler;
        compiler.compileToSPIRV(stageIt->second, buffer, "main", spirvCode);
        // create shader module
        return mDevice.createShaderModule({ {}, spirvCode });
    }
}
