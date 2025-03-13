#include "platform/rs/vulkan/RenderSystemVulkan.hpp"
#include "core/Logging.hpp"
#include "platform/WindowSystem.hpp"
#include "core/SwapChain.hpp"
#include "VulkanContext.hpp"
#include "VulkanSwapchain.hpp"
#include "util/util.hpp"

VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE

namespace pd {
    RenderSystemVulkan::RenderSystemVulkan(VulkanConfig& vulkanConfig)
        : mVulkanConfig(vulkanConfig){
        initVulkanInstance();
    }

    void RenderSystemVulkan::createVmaAllocator() {
        // TODO
    }

    void RenderSystemVulkan::initVulkanInstance() {
        LOG_INFO("initialize Vulkan Library")
            // init dynamic loader
            static vk::DynamicLoader dl;
        VULKAN_HPP_DEFAULT_DISPATCHER.init(dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr"));
        // craete VulkanContext
        VulkanContext vkContext{};
        // create instance
        std::vector<vk::ExtensionProperties> availableInstanceextensions = vk::enumerateInstanceExtensionProperties();
        std::vector<const char*> activeInstanceExtensions({ VK_KHR_SURFACE_EXTENSION_NAME });
        if (mVulkanConfig.enableDebug) {
            activeInstanceExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            // more debug infos
            activeInstanceExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
        }
        activeInstanceExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
        if (!validateExtensions(activeInstanceExtensions, availableInstanceextensions)) {
            throw std::runtime_error("Required instance extensions are missing");
        }
        vk::ApplicationInfo app(mVulkanConfig.appName.c_str(), {}, mVulkanConfig.engineName.c_str(), {}, VK_MAKE_VERSION(1, 0, 0));
        vk::InstanceCreateInfo instanceInfo({}, &app, {}, activeInstanceExtensions);
        // instance create
        LOG_INFO("creating Vulkan instance...")
        vkContext.mInstance = vk::createInstance(instanceInfo);
        VULKAN_HPP_DEFAULT_DISPATCHER.init(vkContext.mInstance);
        // select physical device
        std::vector<vk::PhysicalDevice> gpus = vkContext.mInstance.enumeratePhysicalDevices();
        std::vector<const char*> requiredDeviceExtensions({ VK_KHR_SWAPCHAIN_EXTENSION_NAME });
        if (mVulkanConfig.enableDebug) {
            // TODO : add validation Layers
            // requiredDeviceExtensions.push_back(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
        }
        for (auto i = 0; i < gpus.size(); ++i) {
            vkContext.mPhysicalDevice = gpus[i];
            // check device extensions support
            std::vector<vk::ExtensionProperties> deviceExtensions = vkContext.mPhysicalDevice.enumerateDeviceExtensionProperties();
            if (!validateExtensions(requiredDeviceExtensions, deviceExtensions)) {
                continue;
            }
            std::vector<vk::QueueFamilyProperties> queueFamilyProperties = vkContext.mPhysicalDevice.getQueueFamilyProperties();
            if (queueFamilyProperties.empty()) {
                throw std::runtime_error("no queue family found");
            }
            for (uint32_t j = 0; j < queueFamilyProperties.size(); ++j) {
                vk::QueueFamilyProperties props = queueFamilyProperties[j];
                if (props.queueCount != 0 && (props.queueFlags & vk::QueueFlagBits::eGraphics)) {
                    vkContext.mGraphicsQueueIndex = j;
                    break;
                }
            }
        }
        if (vkContext.mGraphicsQueueIndex == INVALID_VK_INDEX) {
            LOG_ERROR("GPU not support necessary queue family props! Vulkan initial failed")
            throw std::runtime_error("failed to select available physical device");
        }
        // create logical device
        float queuePriority = 1.f;
        vk::DeviceQueueCreateInfo queueInfo({}, vkContext.mGraphicsQueueIndex, 1, &queuePriority);
        vk::DeviceCreateInfo deviceInfo({}, queueInfo, {}, requiredDeviceExtensions);
        // device create
        LOG_INFO("creating Vulkan logical device...")
        vkContext.mDevice = vkContext.mPhysicalDevice.createDevice(deviceInfo);
        VULKAN_HPP_DEFAULT_DISPATCHER.init(vkContext.mDevice);
        vkContext.mGraphicsQueue = vkContext.mDevice.getQueue(vkContext.mGraphicsQueueIndex, 0);
        mVulkanContext = &vkContext;
        // create allocator
        createVmaAllocator();
        if (mVulkanConfig.createDebugPipeline) {
            createDebugPipeline();
        }
    }

    void RenderSystemVulkan::createDebugPipeline() {
        // create renderpass
        vk::AttachmentDescription att(
            {},
            vk::Format::eUndefined,
            vk::SampleCountFlagBits::e1,
            vk::AttachmentLoadOp::eClear,
            vk::AttachmentStoreOp::eStore,
            vk::AttachmentLoadOp::eDontCare,
            vk::AttachmentStoreOp::eDontCare,
            vk::ImageLayout::eUndefined,
            vk::ImageLayout::ePresentSrcKHR
        );
        vk::AttachmentReference colorRef(0, vk::ImageLayout::eColorAttachmentOptimal);
        vk::SubpassDescription subpass({}, vk::PipelineBindPoint::eGraphics, {}, colorRef);
        vk::SubpassDependency dependency(
            VK_SUBPASS_EXTERNAL,
            0,
            vk::PipelineStageFlagBits::eColorAttachmentOutput,
            vk::PipelineStageFlagBits::eColorAttachmentOutput,
            {},
            vk::AccessFlagBits::eColorAttachmentRead | vk::AccessFlagBits::eColorAttachmentWrite
        );
        vk::RenderPassCreateInfo rpInfo({}, att, subpass, dependency);
        mCurrentRenderpass = mVulkanContext->mDevice.createRenderPass(rpInfo);
        // create pipeline layout
        mPipelineLayout = mVulkanContext->mDevice.createPipelineLayout({});
        // create shaderModule
        const auto shaderPath = std::filesystem::current_path() / "assets" / "shaders" / "triangle";
        const auto vertexShaderPath = shaderPath / "triangle.vert";
        const auto fragShaderPath = shaderPath / "triangle.frag";
        auto vertShaderModule = mVulkanContext->createShaderModule(vertexShaderPath.string().c_str());
        auto fragShaderModule = mVulkanContext->createShaderModule(fragShaderPath.string().c_str());
        // create creagphics pipeline
        std::vector<vk::PipelineShaderStageCreateInfo> shader_stages{
            vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eVertex, vertShaderModule, "main"),
            vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eFragment, fragShaderModule, "main") 
        };
        vk::PipelineVertexInputStateCreateInfo vertex_input;

        // Our attachment will write to all color channels, but no blending is enabled.
        std::vector<vk::PipelineColorBlendAttachmentState> blendAttachmentStateVec;
        vk::PipelineColorBlendAttachmentState blend_attachment;
        blend_attachment.colorWriteMask = vk::ColorComponentFlagBits::eR | vk::ColorComponentFlagBits::eG | vk::ColorComponentFlagBits::eB | vk::ColorComponentFlagBits::eA;
        blendAttachmentStateVec.push_back(blend_attachment);
        // Disable all depth testing.
        vk::PipelineDepthStencilStateCreateInfo depth_stencil;

        vk::PipelineInputAssemblyStateCreateInfo input_assembly_state({}, vk::PrimitiveTopology::eTriangleList, false);

        vk::PipelineTessellationStateCreateInfo tessellation_state({}, 0);

        vk::PipelineViewportStateCreateInfo viewport_state({}, 1, nullptr, 1, nullptr);

        vk::PipelineRasterizationStateCreateInfo rasterization_state;
        rasterization_state.polygonMode = vk::PolygonMode::eFill;
        rasterization_state.cullMode = vk::CullModeFlagBits::eBack;
        rasterization_state.frontFace = vk::FrontFace::eClockwise;
        rasterization_state.lineWidth = 1.0f;

        vk::PipelineMultisampleStateCreateInfo multisample_state({}, vk::SampleCountFlagBits::e1);

        vk::PipelineColorBlendStateCreateInfo color_blend_state({}, false, {}, blendAttachmentStateVec);

        std::array<vk::DynamicState, 2>    dynamic_state_enables = { vk::DynamicState::eViewport, vk::DynamicState::eScissor };
        vk::PipelineDynamicStateCreateInfo dynamic_state({}, dynamic_state_enables);

        // Final fullscreen composition pass pipeline
        vk::GraphicsPipelineCreateInfo pipeline_create_info({},
            shader_stages,
            &vertex_input,
            &input_assembly_state,
            &tessellation_state,
            &viewport_state,
            &rasterization_state,
            &multisample_state,
            & depth_stencil,
            &color_blend_state,
            &dynamic_state,
            mPipelineLayout,
            mCurrentRenderpass,
            {},
            {},
            -1);
        mVulkanContext->mDevice.destroyShaderModule(shader_stages[0].module);
        mVulkanContext->mDevice.destroyShaderModule(shader_stages[1].module);
    }

    bool pd::validateExtensions(const std::vector<const char*>& required,
        const std::vector<vk::ExtensionProperties>& available) {
        return std::find_if(required.begin(),
            required.end(),
            [&available](auto extension) {
                return std::find_if(available.begin(),
                    available.end(),
                    [&extension](auto const& ep) {
                        return strcmp(ep.extensionName, extension) == 0;
                    }) == available.end();
                }) == required.end();
    }


    SwapChain* RenderSystemVulkan::createSwapChain(Engine& engine, WindowSystem* windowSystem) {
        // create surface
        void* nativeWindow = windowSystem->getNativeWindow();
        const vk::Win32SurfaceCreateInfoKHR surfaceCreateInfo({}, GetModuleHandle(nullptr), (HWND)nativeWindow, {});
        mVulkanContext->mSurface = mVulkanContext->mInstance.createWin32SurfaceKHR(surfaceCreateInfo);
        vk::Extent2D extent(windowSystem->getExtent().width, windowSystem->getExtent().height);

        return new VulkanSwapChain(engine, mVulkanContext);
    }
}
