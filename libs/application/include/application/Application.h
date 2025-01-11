#ifndef DAWN_PRIMALDAWN_PDAPP_APPLICATION_H
#define DAWN_PRIMALDAWN_PDAPP_APPLICATION_H

#include <string>
#include <memory>
#include "core/Engine.h"
#include "platform/WindowSystem.h"

namespace pd {

    struct AppConfig {
        std::string appName{"default"};
        WindowSystem* window{ nullptr };
    };
    /**
    * @brief 应用，所有渲染实例的主抽象
    */
    class Application {
    public:
        Application();
        virtual ~Application() = default;
        /**
        * @brief 应用执行前的准备工作
        */
        virtual bool prepare(const AppConfig& options);
        
        /**
        * @brief 运行一次
        * @param ms 距离上次经过的毫秒数
        */
        virtual void runOneFrame(float ms);
        /**
        * @brief 应用结束后的工作，比如清理资源
        */
        virtual void finish();

        inline bool shouldClose() const {
            return mClosed;
        }

        inline void close() {
            mClosed = true;
        }

        Application(const Application& app) = delete;
        Application(const Application&& app) = delete;
        Application& operator=(const Application& app) = delete;
        Application& operator=(Application& app) = delete;
    protected:
        float mFps{ 0.f };
        float mFrameTime{ 0.f };
        std::unique_ptr<WindowSystem> mWindowSystem{ nullptr };
        std::unique_ptr<Engine> mEngine{ nullptr };
        std::unique_ptr<SwapChain> mSwapChain = nullptr;
        std::string mName{};
        bool mClosed{ false };
    };
} // namespace pd

#endif
