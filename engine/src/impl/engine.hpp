#pragma once

#include "primaldawn/engine.hpp"

#include <memory>
#include <vector>

#include "primaldawn/config.hpp"
#include "downcast.hpp"

namespace primaldawn {
    class Platform;
    class RenderSystem;
    class Renderer;
    class View;

	class PdEngine : public Engine {
    public:
        /**
        * @brief 创建Engine类
        * 1. 强制使用智能指针，不能直接构造或析构，防止意外构造，拷贝，析构
        * 2. 可在构造前做一些配置
        */
        static inline std::unique_ptr<Engine> Create(config::Engine config);

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
        inline bool IsRunning() const;

        ~PdEngine();
    private:
        explicit PdEngine(config::Engine config);

        config::Engine config_;
        std::unique_ptr<Platform> platform_{ nullptr };
        std::unique_ptr<RenderSystem> render_system_{ nullptr };
        std::unique_ptr<Renderer> renderer_{ nullptr };
        std::vector<std::unique_ptr<View>> views_;
        bool is_running_ = false;
	};

    DOWNCAST(Engine);
}
