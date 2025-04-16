#include "platform/render_system/vulkan/render_context.hpp"

#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"

namespace primaldawn {
    RenderContext::RenderContext(const RenderSystemVulkan& render_system_vulkan)
        : render_system_vulkan_(render_system_vulkan) {
        swapchain_ = std::make_unique<VulkanSwapchain>(render_system_vulkan_);
        // create image views
        render_system_vulkan_.GetContext()->GetLogicalDevice().waitIdle();
        for (auto& each_image : swapchain_->GetImages()) {
        }
        
    }
} // namespace primaldawn
