#pragma once

#include "impl/render_system.hpp"


#include "primaldawn/config.hpp"
#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class VulkanContext;

	class RenderSystemVulkan : public PdRenderSystem {
	public:
		explicit RenderSystemVulkan(config::RenderSystem cfg);
		~RenderSystemVulkan();

		void BindPipeline() override;
		void Draw() override;
	private:
		std::unique_ptr<VulkanContext> vulkan_context_{nullptr};

		VmaAllocator vma_allocator_ = VK_NULL_HANDLE;

		void createAllocator();
	public:
		// movable only
		RenderSystemVulkan(const RenderSystemVulkan&) = delete;
		RenderSystemVulkan& operator=(const RenderSystemVulkan&) = delete;
		RenderSystemVulkan(RenderSystemVulkan&&) noexcept = default;
		RenderSystemVulkan& operator=(RenderSystemVulkan&&) noexcept = default;
	};
} // namespace primaldawn
