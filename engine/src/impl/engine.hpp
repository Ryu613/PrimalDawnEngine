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
        */
        static Engine* Create(config::Engine config);

        /**
        * @brief 关闭引擎
        */
        static void ShutDown(PdEngine* engine);

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
        
        void shutdown();

        config::Engine config_;
        std::unique_ptr<Platform> platform_{ nullptr };
        std::unique_ptr<RenderSystem> render_system_{ nullptr };
        std::unique_ptr<Renderer> renderer_{ nullptr };
        std::vector<std::unique_ptr<View>> views_;
        bool is_running_ = false;
	};

    DOWNCAST(Engine);
}
