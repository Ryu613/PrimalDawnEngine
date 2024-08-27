#pragma once
#include "prequisites.hpp"
#include "macro.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // 读入到场景
        void loadScene(Scene* scene);
        // 卸载当前场景
        void unloadScene();
        // 创建场景
        Scene* createScene(const String& sceneName);
        // 创建相机
        Camera* createCamera(const String& name);
        // 创建光源
        Light* createLight(const String& name);
    };
}