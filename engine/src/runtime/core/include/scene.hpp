/*
    场景，一个场景包含物体，光源，相机等。以场景图（树）组织这些SceneNode
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
        // 场景图根节点
        std::unique_ptr<SceneNode> mSceneNodeRoot;
        // 场景名称
        std::string mSceneName;
        // 场景里的所有相机列表
        CameraList mCameras;
        // 场景节点列表
        SceneNodeList sceneNodeList;
        // 根节点指针
        std::unique_ptr<SceneNode> mSceneRoot;
        // 光线列表
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