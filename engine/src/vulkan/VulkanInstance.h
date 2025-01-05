#pragma once

#include <vulkan/vulkan.hpp>

namespace pd {
    namespace vkcore {
        class VulkanInstance {
        public:
            VulkanInstance(const std::string);
            ~VulkanInstance()
        };
    }
}
