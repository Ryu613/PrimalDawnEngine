#pragma once

#include "impl/render_system.hpp"


#include "primaldawn/config.hpp"
#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class VulkanContext;
	class PdPlatform;
	class RenderContext;
	class RenderPipeline;
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
		explicit RenderSystemVulkan(const PdPlatform* platform, config::RenderSystem cfg);
		~RenderSystemVulkan();

		void BindPipeline() override;
		void Draw() override;

		const PdPlatform* GetPlatform() const;
		const VulkanContext* GetContext() const;
		const vk::SurfaceKHR& GetSurface() const;
		const VulkanSwapchain* GetSwapchain() const;
	private:
		const PdPlatform* platform_{ nullptr };
		std::unique_ptr<VulkanContext> context_{nullptr};
		vk::CommandPool command_pool_ = VK_NULL_HANDLE;
		vk::SurfaceKHR surface_ = VK_NULL_HANDLE;

		VmaAllocator vma_allocator_ = VK_NULL_HANDLE;
		// manage rendering & frame related data
		std::unique_ptr<RenderContext> render_context_;
		// encapsures render pipeline
		std::unique_ptr<RenderPipeline> render_pipeline_;

		void createAllocator();
		void createCommandPool();
		void createSurface();
		void createImageViews();
	public:
		// movable only
		RenderSystemVulkan(const RenderSystemVulkan&) = delete;
		RenderSystemVulkan& operator=(const RenderSystemVulkan&) = delete;
		RenderSystemVulkan(RenderSystemVulkan&&) noexcept = default;
		RenderSystemVulkan& operator=(RenderSystemVulkan&&) noexcept = default;
	};
} // namespace primaldawn
