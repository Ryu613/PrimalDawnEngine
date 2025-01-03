#ifndef DAWN_PRIMALDAWN_ENGINE_PLATFORM_H
#define DAWN_PRIMALDAWN_ENGINE_PLATFORM_H

namespace pd {
    class Driver;
    /**
    * Platform封装了底层API和操作系统，包含各种通用操作
    */
    class Platform {
    public:

        Platform() noexcept = default;

        virtual ~Platform() noexcept = default;

        /**
        * 创建驱动，包含底层图形API初始化
        */
        virtual Driver* createDriver() noexcept = 0;
    };
}

#endif
