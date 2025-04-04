#pragma once

#include <string>
#include <memory>



#include "platform/PlatformEnums.hpp"

namespace pd {
    class SwapChain;
    class Scene;
    class View;
    class Renderer;
    class Platform;
    class WindowSystem;

    struct EngineConfig {
        std::string appName{ "default" };
        Backend backend = Backend::VULKAN;
        WSI wsi = WSI::SDL2;
        bool enableDebug = false;
    };
    /**
    * @brief 引擎主类,一般由Application持有，不可直接实例化
    */
    class Engine {
    public:
        /**
        * @brief 创建引擎
        */
        static std::unique_ptr<Engine> create(EngineConfig& config);
        
        /**
        * @brief 销毁引擎和相关资源
        * 
        * @param engine 引擎指针
        */
        static void destroy(Engine* engine);

        /**
        * @brief 创建交换链
        */
        std::unique_ptr<SwapChain> createSwapChain(WindowSystem* windowSystem) noexcept;

        /**
        * @brief 创建渲染器
        */
        std::unique_ptr<Renderer> createRenderer() noexcept;

        /**
        * @brief 创建场景
        */
        std::unique_ptr<Scene> createScene() noexcept;
        /**
        * @brief 创建视图
        */
        std::unique_ptr<View> createView() noexcept;

        /**
        * 获取所用的图形API
        */
        Backend getBackend() const noexcept;

        /**
        * 获取平台指针
        */
        Platform* getPlatform() const noexcept;

    private:
        /**
        * @brief 初始化引擎，在engine实例化后执行
        */
        void init();

        // 不可直接实例化和销毁
        Engine() noexcept = default;
        Engine(EngineConfig& engineConfig);

        EngineConfig& mEngineConfig;
        std::unique_ptr<Platform> mPlatform{ nullptr };
        std::unique_ptr<WindowSystem> mWindowSystem{ nullptr };
    public:
        ~Engine();
        // 不可拷贝赋值
        Engine(Engine const&) = delete;
        Engine(Engine&) = delete;
        Engine& operator=(Engine const&) = delete;
        Engine& operator=(Engine&&) = delete;
    };
}
