#ifndef DAWN_PRIMALDAWN_ENGINE_H
#define DAWN_PRIMALDAWN_ENGINE_H

#include <memory>

#include "platform/DriverEnums.h"

namespace pd {
    class Platform;
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

        static std::unique_ptr<Engine> create(const Builder& builder);
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

#endif
