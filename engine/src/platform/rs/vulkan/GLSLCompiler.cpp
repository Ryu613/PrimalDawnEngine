#include "GLSLCompiler.hpp"
#include <SPIRV/GlslangToSpv.h>
#include <StandAlone/DirStackFileIncluder.h>
#include <glslang/Public/ResourceLimits.h>
#include <filesystem>

namespace pd {
namespace {
    inline EShLanguage findShaderLanguage(vk::ShaderStageFlagBits stage) {
        switch (stage) {
        case vk::ShaderStageFlagBits::eVertex:
            return EShLangVertex;

        case vk::ShaderStageFlagBits::eTessellationControl:
            return EShLangTessControl;

        case vk::ShaderStageFlagBits::eTessellationEvaluation:
            return EShLangTessEvaluation;

        case vk::ShaderStageFlagBits::eGeometry:
            return EShLangGeometry;

        case vk::ShaderStageFlagBits::eFragment:
            return EShLangFragment;

        case vk::ShaderStageFlagBits::eCompute:
            return EShLangCompute;

        case vk::ShaderStageFlagBits::eRaygenKHR:
            return EShLangRayGen;

        case vk::ShaderStageFlagBits::eAnyHitKHR:
            return EShLangAnyHit;

        case vk::ShaderStageFlagBits::eClosestHitKHR:
            return EShLangClosestHit;

        case vk::ShaderStageFlagBits::eMissKHR:
            return EShLangMiss;

        case vk::ShaderStageFlagBits::eIntersectionKHR:
            return EShLangIntersect;

        case vk::ShaderStageFlagBits::eCallableKHR:
            return EShLangCallable;

        case vk::ShaderStageFlagBits::eMeshEXT:
            return EShLangMesh;

        case vk::ShaderStageFlagBits::eTaskEXT:
            return EShLangTask;

        default:
            return EShLangVertex;
        }
    }
} // namespace

    
    /**
    * 把glsl编译为SPIR-V
    */
    void GLSLCompiler::compileToSPIRV(vk::ShaderStageFlagBits stage,
        const std::vector<char>& glslSource,
        const std::string& entryPoint,
        std::vector<std::uint32_t>& spirv) {
        
        glslang::InitializeProcess();

        EShLanguage language = findShaderLanguage(stage);

        glslang::EshTargetClientVersion clientVersion = glslang::EShTargetVulkan_1_3;
        glslang::EShTargetLanguageVersion langVersion = glslang::EShTargetSpv_1_0;

        if (language == EShLangRayGen || language == EShLangAnyHit ||
            language == EShLangClosestHit || language == EShLangMiss) {
            langVersion = glslang::EShTargetSpv_1_4;
        }

        std::string source = std::string(glslSource.begin(), glslSource.end());

        const char* file_name_list[1] = { "" };
        const char* shader_source = reinterpret_cast<const char*>(source.data());

        glslang::TShader shader(language);
        shader.setStringsWithLengthsAndNames(&shader_source, nullptr, file_name_list, 1);
        shader.setEntryPoint(entryPoint.c_str());
        shader.setSourceEntryPoint(entryPoint.c_str());
        shader.setEnvClient(glslang::EShClientVulkan, clientVersion);
        shader.setEnvTarget(glslang::EShTargetSpv, langVersion);

        const TBuiltInResource* resources = GetDefaultResources();
        const EShMessages messages = static_cast<EShMessages>(
            EShMsgDefault | EShMsgSpvRules | EShMsgVulkanRules | EShMsgDebugInfo);
        DirStackFileIncluder includeDir;
        std::filesystem::path includePath = std::filesystem::current_path();
        includePath = includePath / "assets" / "shaders";
        includeDir.pushExternalLocalDirectory(includePath.string());
        if (!shader.parse(GetDefaultResources(), 100, false, messages, includeDir)) {
            throw std::runtime_error("shader compile error: "
                + std::string(shader.getInfoLog())
            );
        }

        glslang::TProgram program;
        program.addShader(&shader);
        if (!program.link(messages)) {
            throw std::runtime_error("shader compile error: " + std::string(program.getInfoLog()));
        }

        glslang::TIntermediate* intermediate = program.getIntermediate(language);

        // Translate to SPIRV.
        if (!intermediate) {
            throw std::runtime_error("Failed to get shared intermediate code: " + std::string(program.getInfoLog()));
        }

        glslang::GlslangToSpv(*intermediate, spirv);

        glslang::FinalizeProcess();
    }
}
