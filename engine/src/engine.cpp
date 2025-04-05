#include "impl/engine.hpp"

#include "primaldawn/view.hpp"

namespace primaldawn {

    std::unique_ptr<Engine> Engine::Create(config::Engine config) {
        return PdEngine::Create(config);
    }

    /**
    * @brief 关闭引擎
    */
    void Engine::ShutDown() {
        return downcast(this)->ShutDown();
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
    void Engine::AddView(std::unique_ptr<View> view) {
        return downcast(this)->AddView(std::move(view));
    }

    /**
    * @brief 当前是否在运行
    */
    bool Engine::IsRunning() const {
        return downcast(this)->IsRunning();
    }
}
