#pragma once

// 防止vulkan的全局函数定义产生冲突
#ifdef _WIN32
// 防止与windows.h里的min/max冲突
#define NOMINMAX
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#define VK_NO_PROTOTYPES
#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
#include "vulkan/vulkan.hpp"
#include "vma/vk_mem_alloc.h"

namespace primaldawn {
	namespace {
		constexpr uint32_t const INVALID_VK_INDEX = 0xFFFFFFFF;
	}
}
