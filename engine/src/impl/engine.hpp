#pragma once

#include "primaldawn/engine.hpp"

#include <memory>

#include "primaldawn/config.hpp"
#include "downcast.hpp"

namespace primaldawn {
    class PdPlatform;
    class PdRenderSystem;
    class Renderer;
    class Scene;
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
        static void Destroy(PdEngine* engine);

        /**
        * @brief 开始运行
        */
        void Run();

        /**
        * @brief 添加视图
        */
        Scene* CreateScene();

        /**
        * @brief 当前是否在运行
        */
        inline bool IsRunning() const;

        ~PdEngine();
    private:
        explicit PdEngine(config::Engine config);
        
        void shutdown();

        bool is_running_ = false;
        config::Engine config_;
        // 注意声明顺序影响析构顺序！
        std::unique_ptr<PdPlatform> platform_{ nullptr };
        std::unique_ptr<PdRenderSystem> render_system_{ nullptr };
        std::unique_ptr<Renderer> renderer_{ nullptr };
        std::unique_ptr<Scene> scene_{ nullptr };
        std::unique_ptr<View> view_{ nullptr };
	};

    DOWNCAST(Engine);
}
