#pragma once

#ifdef _WIN32
#include <glslang/Public/ShaderLang.h>
#endif

#include <string>
#include <vector>

#include "VulkanCommon.hpp"

namespace pd {
	class VulkanContext;

	class VulkanShaderModule final {
	public:
		explicit VulkanShaderModule(const VulkanContext* context,
			const std::string& filepath,
			const std::string& entryPoint,
			VkShaderStageFlagBits stages,
			const std::string& name);
		~VulkanShaderModule();

		vk::ShaderModule getVkShaderModule() const;
		vk::ShaderStageFlagBits getVkShaderStageFlags() const;
		const std::string& getEntryPoint() const;

	private:
		std::vector<char> glslToSpirv(const std::vector<char>& data,
			EShLanguage shaderStage,
			const std::string& shaderDir,
			const char* entryPoint);

		void createShader(const std::string& filepath,
			const std::string& entryPoint,
			const std::string& name);

		EShLanguage getShaderStageFromFileName(const std::string& fileName);

	private:
		const VulkanContext* mContext = nullptr;
		vk::ShaderModule mVkShaderModule = VK_NULL_HANDLE;
		vk::ShaderStageFlagBits mVkStageFlags;
		std::string mEntryPoint;
	};
}
