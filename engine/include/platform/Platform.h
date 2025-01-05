#pragma once

namespace pd {
    class Driver;
    /**
    * Platform封装了底层API和操作系统，包含各种通用操作
    */
    class Platform {
    public:

        Platform() noexcept = default;

        virtual ~Platform() noexcept = default;

        virtual Driver* createDriver() noexcept = 0;
    };
}
