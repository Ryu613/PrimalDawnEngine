#pragma once

#include <memory>
#include <vector>
#include <string>

namespace pd {
    class View;
    class Platform;
    class WindowSystem;
    class RenderSystem;
    class Renderer;

    struct RenderSystem::Config;
    struct Platform::Config;
    struct Renderer::Config;

    /**
    * @brief 引擎主类,一般由Application持有
    */
	class Engine {
	public:
        struct Config {
            std::string appName{ "default" };
            RenderSystem::Config renderSystemConfig;
            Platform::Config platformConfig;
            Renderer::Config rendererConfig;
            bool enableDebug = false;
        };

        /**
        * @brief 创建Engine类
        * 强制使用智能指针，不能直接构造或析构，防止意外拷贝
        */
        static std::unique_ptr<Engine> create(Config config);

        /**
        * @brief 关闭引擎
        */
        void shutdown();

        /**
        * @brief 添加视图
        */
        void addView(std::unique_ptr<View> view);

        /**
        * @brief 开始运行
        */
        void run();

        bool isRunning() const {
            return mIsRunning;
        }

    private:
        Engine(Config config);
        ~Engine();

        Config& mConfig;
        std::unique_ptr<Platform> mPlatform;
        std::unique_ptr<RenderSystem> mRenderSystem;
        std::unique_ptr<Renderer> mRenderer;
        std::vector<std::unique_ptr<View>> mViews;
        bool mIsRunning = false;
	};
}
