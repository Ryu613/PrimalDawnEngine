#include "platform/render_system/vulkan/render_context.hpp"

#include "platform/render_system/render_system_vulkan.hpp"
#include "platform/render_system/vulkan/vulkan_context.hpp"
#include "platform/render_system/vulkan/vulkan_swapchain.hpp"
#include "platform/render_system/vulkan/render_frame.hpp"
#include "platform/render_system/vulkan/render_target.hpp"

namespace primaldawn {
    RenderContext::RenderContext(const RenderSystemVulkan& render_system_vulkan)
        : render_system_vulkan_(render_system_vulkan) {
        // create swapchain
        swapchain_ = std::make_unique<VulkanSwapchain>(render_system_vulkan_);
        // fill up render frames
        GetVulkanContext()->GetLogicalDevice().waitIdle();
        for (auto& image : swapchain_->GetImages()) {
            frames_.emplace_back(std::make_unique<RenderFrame>(*this, image));
        }
    }

    const VulkanContext* RenderContext::GetVulkanContext() const {
        return render_system_vulkan_.GetContext();
    }

    const VulkanSwapchain* RenderContext::GetVulkanSwapchain() const {
        return swapchain_.get();
    }
} // namespace primaldawn
