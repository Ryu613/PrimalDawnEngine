#pragma once
#include "prequisites.hpp"
#include "macro.hpp"

namespace PrimalDawn {
    class SceneManager {
    private:
        Scene* currentScene;
    public:
        // ���뵽����
        void loadScene(Scene* scene);
        // ж�ص�ǰ����
        void unloadScene();
        // ��������
        Scene* createScene(const String& sceneName);
        // ����ʵ��(����Ԥ����Ļ�������ͼ��)
        Entity* createEntity(enum ENTITY_TYPE entityType);
        // �������
        Camera* createCamera(const String& name);
        // ������Դ
        Light* createLight(const String& name);
    };
}