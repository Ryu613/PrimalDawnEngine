#pragma once

#include "VulkanCommon.hpp"
#include <GLSLANG/Public/ShaderLang.h>

namespace pd {
	class GLSLCompiler {
	public:
		void compileToSPIRV(vk::ShaderStageFlagBits stage,
			const std::vector<char>& glslSource,
			const std::string& entryPoint,
			std::vector<std::uint32_t>& spirv);
	};
}
