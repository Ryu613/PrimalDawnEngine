#pragma once

#include "primaldawn/config.hpp"
#include "platform/render_system/vulkan/vulkan_common.hpp"

namespace primaldawn {
	class VulkanContext {
	public:
		struct VulkanConfig : public config::RenderSystem {
			bool use_debug_utils = false;
			bool use_debug_report = false;
		};
		explicit VulkanContext(VulkanConfig cfg);
		~VulkanContext();
	private:
		VulkanConfig vulkan_config_;
		vk::Instance instance_ = VK_NULL_HANDLE;
		vk::PhysicalDevice physical_device_ = VK_NULL_HANDLE;
		vk::Device logic_device_ = VK_NULL_HANDLE;
		uint32_t graphics_queue_index_ = INVALID_VK_INDEX;
		vk::Queue graphics_queue_ = VK_NULL_HANDLE;

		friend class RenderSystemVulkan;
	};

	/**
	* 判断需求的扩展是否都支持
	* @return false 至少一个扩展不支持
	* @return true 全部需求的扩展都支持
	*/
	inline bool ValidateExtensions(const std::vector<const char*>& required,
		const std::vector<vk::ExtensionProperties>& available);

	bool HasExtensions(const char* required, const std::vector<vk::ExtensionProperties>& available);

} // namespace primaldawn
