#pragma once

#include "primaldawn/engine.hpp"

#include <memory>

#include "primaldawn/config.hpp"
#include "downcast.hpp"
#include "allocators.hpp"

namespace primaldawn {
    class PdPlatform;
    class PdRenderSystem;
    class PdRenderer;
    class PdScene;
    class PdView;
    class PdCamera;

	class PdEngine : public Engine {
    public:
        void* operator new(const std::size_t size) noexcept {
            return ::utils::aligned_alloc(size, alignof(PdEngine));
        }

        void operator delete(void* p) noexcept {
            ::utils::aligned_free(p);
        }
    public:
        /**
        * @brief 创建Engine类
        */
        static PdEngine* Create(const config::Engine& config);

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
        PdScene* CreateScene();

        PdCamera* CreateCamera();

        /**
        * @brief 当前是否在运行
        */
        inline bool IsRunning() const;

        ~PdEngine();
    private:
        explicit PdEngine(const config::Engine& config);
        
        void shutdown();

        bool is_running_ = false;
        config::Engine config_;
        // 注意声明顺序影响析构顺序！
        std::unique_ptr<PdPlatform> platform_{ nullptr };
        std::unique_ptr<PdRenderSystem> render_system_{ nullptr };
        std::unique_ptr<PdRenderer> renderer_{ nullptr };
        std::unique_ptr<PdScene> scene_{ nullptr };
        std::unique_ptr<PdView> view_{ nullptr };
	};

    DOWNCAST(Engine);
}
