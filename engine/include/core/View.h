#pragma once

namespace pd {
    class Scene;
    class Camera;
    /**
    * @brief 视图包含所有渲染时需要的信息
    * renderer调用render()时传入View，view包括了:
    * - Scene
    * - Camera
    * - Viewport
    * - 其他渲染参数
    */
    class View {
    public:
        View(Engine& engine);
        ~View() noexcept;
        void setScene(Scene* scene) { mScene = scene; }
        Scene* getScene() const noexcept { return mScene };
    private:
        Scene* mScene;
        Camera* mCamera;
    };
}
