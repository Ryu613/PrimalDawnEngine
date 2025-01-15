#pragma once

#include <memory>

#include "core/SwapChain.h"

#include "platform/PlatformEnums.h"
#include "platform/Platform.h"

namespace pd {
    class WindowSystem;
    class Renderer;
    class View;
    /**
    * @brief 引擎主类
    */
    class Engine {
    public:
        /**
        * @brief 用于更方便地创建引擎
        */
        class Builder {
            friend class Engine;
        public:
            /**
            * @brief 设置图形底层API
            */
            Builder& backend(Backend backend) noexcept;
            Builder() noexcept;
            Builder(Builder const& rhs) noexcept;
            Builder(Builder&& rhs) noexcept;
            ~Builder() noexcept;
            Builder& operator=(Builder const& rhs) noexcept;
            Builder& operator=(Builder&& rhs) noexcept;
            /**
            * @brief 创建引擎实例，返回指针
            */
            std::unique_ptr<Engine> build() const;
        private:
            Backend mBackend = Backend::VULKAN;
        };
        /**
        * @brief 获取引擎指针
        */
        static Engine* getEngine();
        
        /**
        * @brief 销毁引擎和相关资源
        * 
        * @param engine 引擎指针
        */
        static void destroy(Engine* engine);

        /**
        * @brief 创建引擎
        */
        static std::unique_ptr<Engine> create(const Builder& builder);

        /**
        * @brief 创建交换链
        */
        std::unique_ptr<SwapChain> createSwapChain(WindowSystem* windowSystem) noexcept;

        /**
        * @brief 创建渲染器
        */
        std::unique_ptr<Renderer> createRenderer() noexcept;
        /**
        * @brief 创建视图
        */
        std::unique_ptr<View> createView() noexcept;
    private:
        /**
        * @brief 初始化引擎，在create时执行
        */
        void init();

        void setBackend(Backend backend);

        Backend mBackend = Backend::VULKAN;
        std::unique_ptr<Platform> mPlatform = nullptr;
    };
}
