#pragma once
// 防止vulkan的全局函数定义产生冲突
#ifdef _WIN32
// 防止与windows.h里的min/max冲突
#define NOMINMAX
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#define VK_NO_PROTOTYPES
#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
#include <vulkan/vulkan.hpp>
// 可以把Vulkan的枚举名称转成字符串，方便打印日志
#include <vulkan/vk_enum_string_helper.h>
#include "vma/vk_mem_alloc.h"

// 日志
#include "core/Logging.hpp"

// 其他公共头
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

// 智能移动构造函数
#define MOVABLE_ONLY(CLASS_NAME)                     \
  CLASS_NAME(const CLASS_NAME&) = delete;            \
  CLASS_NAME& operator=(const CLASS_NAME&) = delete; \
  CLASS_NAME(CLASS_NAME&&) noexcept = default;       \
  CLASS_NAME& operator=(CLASS_NAME&&) noexcept = default;

// 处理vulkan函数的返回值，若有错误就打印(HPP不需要)
#define VK_CHK(func)                                                                   \
  {                                                                                    \
    const VkResult result = func;                                                      \
    if (result != VK_SUCCESS) {                                                        \
      std::cerr << "Error calling function " << #func << " at " << __FILE__ << ":"     \
                << __LINE__ << ". Result is " << string_VkResult(result) << std::endl; \
      assert(false);                                                                   \
    }                                                                                  \
  }

// 常量

namespace {
    constexpr uint32_t const INVALID_VK_INDEX = 0xFFFFFFFF;
}
