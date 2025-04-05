#pragma once
#include "VulkanCommon.hpp"
#include "platform/PlatformEnums.hpp"
#include "core/RenderSystem.hpp"

namespace pd {
	class VulkanContext;

	struct VulkanConfig : public RenderSystemConfig {
		// TODO: vulkan layers & extensions can be set here
		bool createDebugPipeline = false;
	};
	/**
	*  Vulkan渲染系统
	*/
	class RenderSystemVulkan : public RenderSystem {
	public:
		RenderSystemVulkan(VulkanConfig& vulkanConfig);
		~RenderSystemVulkan();

		std::unique_ptr<SwapChain> createSwapChain(Engine& engine, WindowSystem* windowSystem) override;

		void bindPipeline(const PipelineDesc& pipelineDesc) override;

		void draw(PipelineDesc desc) override;

		void beginRenderPass() override;

		void endRenderPass() override;

	private:

		void initVulkanInstance();

		void createVmaAllocator();

		void createDebugPipeline();

		void initFrameBuffers();

		VulkanConfig& mVulkanConfig;

		std::unique_ptr<VulkanContext> mVulkanContext = nullptr;

		vk::RenderPass mCurrentRenderpass = nullptr;
		vk::Pipeline mPipeline = nullptr;
		vk::PipelineLayout mPipelineLayout = nullptr;

		//vk::Instance mInstance = VK_NULL_HANDLE;
		//vk::PhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
		//uint32_t mGraphicsQueueIndex = INVALID_VK_INDEX;
		//vk::SurfaceKHR mSurface = VK_NULL_HANDLE;
		//vk::Device mDevice = VK_NULL_HANDLE;
		//vk::Queue mGraphicsQueue = VK_NULL_HANDLE;
		//// debug
		//vk::RenderPass mDebugRenderpass = VK_NULL_HANDLE;
		//vk::PipelineLayout mDebugPipelineLayout = VK_NULL_HANDLE;
		//vk::Pipeline mDebugPipeline = VK_NULL_HANDLE;

	};


	bool validateExtensions(const std::vector<const char*>& required,
	    const std::vector<vk::ExtensionProperties>& available);
}
