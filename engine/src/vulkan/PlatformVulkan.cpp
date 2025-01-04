#include "platform/PlatformVulkan.h"
#include "platform/Driver.h"
#include "core/util/Logging.h"

#include"lumavk/LumaVk.h"

using namespace pd;

Driver* PlatformVulkan::createDriver() noexcept {
    // 初始化vulkan
    if (!lumavk::init()) {
        LOG_ERROR("LumaVk initialize error!");
        throw std::runtime_error("failed to initialize LumaVk");
    }
    return nullptr;
}

