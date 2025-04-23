#include "impl/engine.hpp"

#include "impl/scene.hpp"

namespace primaldawn {

    Engine* Engine::Create(const config::Engine* config) noexcept {
        if (!config) {
            config::Engine default_config;
            config = &default_config;
        }
        return PdEngine::Create(*config);
    }

    /**
    * @brief 关闭引擎
    */
    void Engine::Destroy(Engine* engine) {
        return PdEngine::Destroy(downcast(engine));
    }

    /**
    * @brief 开始运行
    */
    void Engine::Run() {
        return downcast(this)->Run();
    }

    /**
    * @brief 添加视图
    */
    Scene* Engine::CreateScene() noexcept {
        return downcast(this)->CreateScene();
    }

    /**
    * @brief 当前是否在运行
    */
    bool Engine::IsRunning() const {
        return downcast(this)->IsRunning();
    }
}
