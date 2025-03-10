#pragma once
#include "VulkanCommon.hpp"
#include "platform/PlatformEnums.hpp"
#include "core/RenderSystem.hpp"

namespace pd {
	struct VulkanConfig {
		std::string appName{ "default" };
		std::string engineName{ "Primal Dawn" };
		OS os = OS::WINDOWS;
		bool enableDebug = false;
	};
	/**
	*  Vulkan渲染系统
	*/
	class RenderSystemVulkan : public RenderSystem {
	public:
		RenderSystemVulkan(VulkanConfig& vulkanConfig);
		~RenderSystemVulkan() = default;

		SwapChain* createSwapChain(Engine& engine, WindowSystem* windowSystem) override;
	private:

		void initVulkanInstance();

		VulkanConfig& mVulkanConfig;

		vk::Instance mInstance = VK_NULL_HANDLE;
		vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
		uint32_t mGraphicsQueueIndex = 0xFFFFFFFF;
		vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
		vk::Device mDevice = VK_NULL_HANDLE;
		vk::Queue mGraphicsQueue = VK_NULL_HANDLE;
	};


	bool validateExtensions(const std::vector<const char*>& required,
	    const std::vector<vk::ExtensionProperties>& available);
}
