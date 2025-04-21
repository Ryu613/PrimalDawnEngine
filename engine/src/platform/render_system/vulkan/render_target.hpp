#pragma once

#include "platform/render_system/render_system_vulkan.hpp"

namespace primaldawn {
    class ImageBundle;
    class RenderTarget {
    public:
        explicit RenderTarget(const RenderSystemVulkan& render_system_vulkan, std::vector<ImageBundle>& iamge_bundles);
    private:
        const RenderSystemVulkan& render_system_vulkan_;
        std::vector<ImageBundle> image_bundles;
    };
} // namespace primaldawn
