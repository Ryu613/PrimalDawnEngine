#pragma once

#include <string>

namespace pd {
    /**
    * @brief 窗口系统
    */
    class WindowSystem {
    public:
        struct Extent {
            unsigned int width = 1024;
            unsigned int height = 768;
        };

        enum class WindowSystemMode {
            Headless,
            FullScreen,
            Borderless,
            Default
        };

        struct WindowSystemOptions {
            std::string title{};
            WindowSystemMode windowSystemMode = WindowSystemMode::Default;
            bool resizable = true;
            Extent extent{ 1024, 768 };
        };

        /**
        * @brief 构造一个窗口系统
        */
        WindowSystem(const WindowSystemOptions& windowSystemOptions);

        virtual ~WindowSystem() = default;

        /**
        * @brief 用于检查窗口是否应该被关闭
        */
        virtual bool shouldClose() = 0;

        /**
        * @brief 处理窗口事件
        */
        virtual void doEvents();

        /**
        * @brief 关闭窗口
        */
        virtual void close() = 0;

        /**
        *   @brif 根据窗口系统获得操作系统原生窗口的指针
        */
        virtual void* getNativeWindow() const = 0;

        /**
        * @brief 处理输入事件
        */
        virtual void processInput() = 0;

        Extent getExtent() const;
    protected:
        WindowSystemOptions mWindowSystemOptions;
        bool mClosed = false;

    };
}
