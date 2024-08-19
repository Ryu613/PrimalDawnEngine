#pragma once
#include "macro.hpp"
#include "scene.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // 读入到场景
        void loadScene(Scene* scene);
        // 卸载当前场景
        void unloadScene();


    };
}