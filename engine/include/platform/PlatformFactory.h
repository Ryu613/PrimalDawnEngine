#pragma once

#include <memory>
#include "platform/DriverEnums.h"
#include "platform/Platform.h"

namespace pd {

    /**
    * @brief 根据图形API创建对应平台,平台对图形API做了统一封装
    */
    class PlatformFactory {
    public:
        /**
        * 根据backend创建平台类，这里的backend只代表偏好，实际看情况
        */
        static std::unique_ptr<Platform> create(Backend* backend) noexcept;
    };
}
