#pragma once

#include "VulkanCommon.hpp"
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

		initVulkanInstance();

		VulkanConfig& mVulkanConfig;

		vk::Instance mInstance = VK_NULL_HANDLE;
		vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
		uint32_t mGraphicsQueueIndex = 0xFFFFFFFF;
		vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
		vk::Device mDevice = VK_NULL_HANDLE;
		vk::Queue mGraphicsQueue = VK_NULL_HANDLE;
	};
}
