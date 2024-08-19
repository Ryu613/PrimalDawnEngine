#pragma once
#include "macro.hpp"
#include "scene.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // ���뵽����
        void loadScene(Scene* scene);
        // ж�ص�ǰ����
        void unloadScene();


    };
}