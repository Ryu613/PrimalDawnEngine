#pragma once
// 防止与windows.h里的min/max冲突
#define NOMINMAX
// 防止vulkan的全局函数定义产生冲突
#define VK_NO_PROTOTYPES
#define VK_USE_PLATFORM_WIN32_KHR
#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
#include <vulkan/vulkan.hpp>
// 可以把Vulkan的枚举名称转成字符串，方便打印日志
#include <vulkan/vk_enum_string_helper.h>

// 日志
#include <core/Logging.h>

// 其他公共头
#include <iostream>
#include <cassert>

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
