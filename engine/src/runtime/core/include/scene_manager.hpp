#pragma once
#include "macro.hpp"
#include "scene.hpp"
#include "entity.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // 读入到场景
        void loadScene(Scene* scene);
        // 卸载当前场景
        void unloadScene();
        // 创建实体(程序预定义的基础几何图形)
        Entity* createEntity(enum ENTITY_TYPE entityType);

    };
}