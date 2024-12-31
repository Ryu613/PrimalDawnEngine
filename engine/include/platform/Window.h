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
    protected:
        WindowOptions mOptions;
    };
}

#endif
