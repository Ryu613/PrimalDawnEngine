#pragma once

#include "platform/PlatformEnums.hpp"
#include "core/RenderSystem.hpp"

namespace pd {
	struct VulkanConfig {
		OS os;
		bool enableDebug = false;
	};
	/**
	*  Vulkan渲染系统
	*/
	class RenderSystemVulkan : public RenderSystem {
		friend class RenderSystemFactory;
	private:
		RenderSystemVulkan(VulkanConfig& vulkanConfig);
		~RenderSystemVulkan();
	};
}
