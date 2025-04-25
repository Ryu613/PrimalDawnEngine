#pragma once

#include "impl/render_system.hpp"

#include <vector>
#include <memory>

#include "platform/render_system/vulkan/vulkan_common.hpp"
#include "primaldawn/config.hpp"

namespace primaldawn {
	class VulkanContext;
	class PdPlatform;
	class RenderContext;
	class RenderPipeline;
	struct SwapchainBuffer {
		vk::Image image;
		vk::ImageView view;
	};
	/**
	* @brief vulkan render system
	* 
	* init order:
	* 1. vulkan context
	* 2. vma allocator
	* 3. command pool(command buffers)
	* 4. surface
	* 5. swapchain
	* 6. image view
	* 7. render pass
	* 8. frame buffer
	* 9. command buffer
	*/
	class RenderSystemVulkan : public PdRenderSystem {
	public:
		explicit RenderSystemVulkan(const PdPlatform& platform, const config::RenderSystem& cfg);
		~RenderSystemVulkan();

		void BindPipeline() override;
		void Draw() override;

		const VulkanContext& GetContext() const;
		const vk::SurfaceKHR& GetSurface() const;
		const vk::Format& GetDepthFormat() const;
		const VmaAllocator& GetMemoryAllocator() const;
	private:
		struct Semaphores {
			vk::Semaphore acquired_image_ready;
			vk::Semaphore render_complete;
		} semaphores_;
		struct DepthStencil {
			vk::Image image;
			vk::DeviceMemory mem;
			vk::ImageView view;
		} depth_stencil_;
		std::unique_ptr<VulkanContext> context_{nullptr};
		vk::CommandPool command_pool_ = VK_NULL_HANDLE;
		vk::SurfaceKHR surface_ = VK_NULL_HANDLE;

		VmaAllocator vma_allocator_ = VK_NULL_HANDLE;
		// manage rendering & frame related data
		std::unique_ptr<RenderContext> render_context_;
		// encapsulate render pipeline
		std::unique_ptr<RenderPipeline> render_pipeline_;
		vk::SubmitInfo submit_info_;
		std::vector<vk::CommandBuffer> draw_cmd_buffers_;
		std::vector<vk::Fence> wait_fences_;
		vk::RenderPass render_pass_;
		vk::PipelineCache pipeline_cache_;
		std::vector<vk::Framebuffer> frame_buffers_;
		std::vector<SwapchainBuffer> swapchain_buffers_;
		vk::Format depth_format_;

		void setupDepthFormat();
		void createAllocator();
		void createSwapchainBuffers();
		void createCommandPool();
		void createSurface();
		void createSyncObject();
		void createCommandBuffers();
		void createSyncPrimitives();
		void setupDepthStencil();
		void setupRenderPass();
		void createPipelineCache();
		void setupFrameBuffer();
	};
} // namespace primaldawn
