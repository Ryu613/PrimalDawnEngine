#include "platform/render_system/render_system_vulkan.hpp"

#define VMA_IMPLEMENTATION
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#include "vma/vk_mem_alloc.h"

#include "platform/render_system/vulkan/vulkan_context.hpp"

namespace primaldawn {
    RenderSystemVulkan::RenderSystemVulkan(config::RenderSystem cfg)
        :PdRenderSystem(std::move(cfg)) {
        // google-filament vulkan init ref:
        // x vulkanPlatform
        // x resourceManager
        // (delay) vulkanSwapchain
        // (delay) vulkanRenderTarget
        // (delay) VulkanRenderPass
        // √ VmaAllocator
        // (optional) VkDebugReportCallbackExt
        // √ VulkanContext
        // √ VulkanCommands
        // √ VulkanPipelineLayoutCache
        // √ VulkanPipelineCache
        // √ VulkanStagePool
        // √ VulkanFboCache
        // √ VulkanSamplerCache
        // √ VulkanBlitter
        // √ VulkanReadPixels
        // √ VulkanDescriptorSetManager
        // √ VulkanQueryManager
        // (delay) struct BoundPipeline
        // (delay) struct RenderPassFboInfo
        // √ other params

        /**
        * vulkan init order:
        * 
        * 1. vulkan context
        * 2. vma allocator
        */
        vulkan_context_ = std::make_unique<VulkanContext>(static_cast<VulkanContext::VulkanConfig>(cfg));
        createAllocator();
    }

    RenderSystemVulkan::~RenderSystemVulkan() {

    }

    void RenderSystemVulkan::BindPipeline() {

    }

    void RenderSystemVulkan::Draw() {

    }

    void RenderSystemVulkan::createAllocator() {
        VmaVulkanFunctions const funcs{
            .vkGetInstanceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetInstanceProcAddr,
            .vkGetDeviceProcAddr = VULKAN_HPP_DEFAULT_DISPATCHER.vkGetDeviceProcAddr,
        };
        VmaAllocatorCreateInfo const allocatorInfo{
            .physicalDevice = vulkan_context_->physical_device_,
            .device = vulkan_context_->logic_device_,
            .pVulkanFunctions = &funcs,
            .instance = vulkan_context_->instance_,
        };
        vmaCreateAllocator(&allocatorInfo, &vma_allocator_);
    }
} // namespace primaldawn
