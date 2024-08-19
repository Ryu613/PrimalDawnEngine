/*
    ������һ�������������壬��Դ������ȡ��Գ���ͼ��������֯��ЩSceneNode
*/
#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "scene_node.hpp"
#include "camera.hpp"
#include "light.hpp"

namespace PrimalDawn {
    class Scene {
    protected:
        typedef std::vector<SceneNode*> SceneNodeList;
        typedef std::map<std::string, Camera*> CameraList;
        typedef std::vector<Light*> LightList;
    private:
        // ����ͼ���ڵ�
        std::unique_ptr<SceneNode> mSceneNodeRoot;
        // ��������
        std::string mSceneName;
        // ���������������б�
        CameraList mCameras;
        // �����ڵ��б�
        SceneNodeList sceneNodeList;
        // ���ڵ�ָ��
        std::unique_ptr<SceneNode> mSceneRoot;
        // �����б�
        LightList mLightList;
    public:
        Scene();
        Scene(std::string& name);
        ~Scene();
        void setName(std::string& sceneName);
        std::string& getName();
        SceneNode* getSceneNodeRoot();
        SceneNode* getSceneNode(const std::string& name) const;
        void addCamera(Camera* camera);
        
    };
}