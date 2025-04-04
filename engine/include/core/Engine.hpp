#pragma once

#include <memory>
#include <vector>

#include "core/engine_config.hpp"

namespace primaldawn {
    class View;
    class Platform;
    class RenderSystem;
    class Renderer;
    /**
    * @brief 引擎主类,一般由Application持有
    */
	class Engine {
	public:

        /**
        * @brief 创建Engine类
        * 1. 强制使用智能指针，不能直接构造或析构，防止意外构造，拷贝，析构
        * 2. 可在构造前做一些配置
        */
        static std::unique_ptr<Engine> Create(EngineConfig config);

        /**
        * @brief 关闭引擎
        */
        void ShutDown();

        /**
        * @brief 开始运行
        */
        void Run();

        /**
        * @brief 添加视图
        */
        inline void AddView(std::unique_ptr<View> view);
        
        /**
        * @brief 当前是否在运行
        */
        inline bool IsRunning() const {
            return is_running_;
        }

        // 不允许移动拷贝
        Engine(const Engine& engine) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(Engine&&) = delete;

        ~Engine();
    private:
        explicit Engine(EngineConfig config);

        EngineConfig& engine_config_;
        std::unique_ptr<Platform> platform_{nullptr};
        std::unique_ptr<RenderSystem> render_system_{ nullptr };
        std::unique_ptr<Renderer> renderer_{ nullptr };
        std::vector<std::unique_ptr<View>> views_;
        bool is_running_ = false;
	};
} // namespace primaldawn
