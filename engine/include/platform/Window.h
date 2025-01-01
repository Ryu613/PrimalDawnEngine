#ifndef DAWN_PRIMALDAWN_ENGINE_WINDOW_H
#define DAWN_PRIMALDAWN_ENGINE_WINDOW_H

#include <string>

namespace pd {
    /**
    * @brief 窗口系统的封装
    */
    class Window {
    public:
        struct Extent {
            unsigned int width = 1024;
            unsigned int height = 768;
        };

        enum class WindowMode {
            Headless,
            FullScreen,
            Borderless,
            Default
        };

        struct WindowOptions {
            std::string title{};
            WindowMode windowMode = WindowMode::Default;
            bool resizable = true;
            Extent extent{ 1024, 768 };
        };

        /**
        * @brief 构造一个窗口系统
        */
        Window(const WindowOptions& windowOptions);

        virtual ~Window() = default;

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
    protected:
        WindowOptions mWindowOptions;
    };
}

#endif
