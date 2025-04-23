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
		explicit VulkanContext(const VulkanConfig& cfg);
		~VulkanContext();

		const VulkanConfig& GetVulkanConfig() const;
		const vk::Instance& GetInstance() const;
		const vk::PhysicalDevice& GetPhysicalDevice() const;
		const vk::Device& GetLogicalDevice() const;
		const uint32_t GetGraphicsQueueIndex() const;
		const vk::Queue& GetGraphicsQueue() const;
		/**
		* @brief 检查GPU是否支持指定的内存类型
		*/
		uint32_t GetMemoryType(uint32_t bits, vk::MemoryPropertyFlags props) const;
	private:
		VulkanConfig vulkan_config_;
		vk::Instance instance_ = VK_NULL_HANDLE;
		vk::PhysicalDevice physical_device_ = VK_NULL_HANDLE;
		vk::Device logic_device_ = VK_NULL_HANDLE;
		uint32_t graphics_queue_index_ = INVALID_VK_INDEX;
		vk::Queue graphics_queue_ = VK_NULL_HANDLE;

		// debug
		vk::DebugUtilsMessengerEXT debug_utils_messenger_ = VK_NULL_HANDLE;
		vk::DebugReportCallbackEXT debug_report_callback_ = VK_NULL_HANDLE;

	public:
		VulkanContext(const VulkanContext&) = delete;
		VulkanContext& operator=(const VulkanContext&) = delete;
		VulkanContext(VulkanContext&&) noexcept = delete;
		VulkanContext& operator=(VulkanContext&&) noexcept = delete;
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
