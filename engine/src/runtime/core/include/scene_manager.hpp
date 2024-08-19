#pragma once
#include "macro.hpp"
#include "scene.hpp"
#include "entity.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // ���뵽����
        void loadScene(Scene* scene);
        // ж�ص�ǰ����
        void unloadScene();
        // ����ʵ��(����Ԥ����Ļ�������ͼ��)
        Entity* createEntity(enum ENTITY_TYPE entityType);

    };
}