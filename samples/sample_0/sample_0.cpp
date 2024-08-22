#include "application_context.hpp"
#include "entity.hpp"
#include "scene_node.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "light.hpp"


using namespace PrimalDawn;
Engine* engine = nullptr;

Scene* createTestScene() {
    SceneManager* scnMgr = engine->getSceneManager();
    String sceneName("scene0");
    Scene* scene = scnMgr->createScene(sceneName);
    // 创建1个球1个立方体
    Entity* sphere = scnMgr->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_SPHERE);
    Entity* cube = scnMgr->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_CUBE);
    // 创建场景节点并关联物体
    SceneNode* nodeCube = scene->getSceneNodeRoot()->createChildSceneNode("primitiveCube");
    SceneNode* nodeSphere = scene->getSceneNodeRoot()->createChildSceneNode("primitiveSphere");
    // 为2个实体设置位置和方向
    nodeCube->setPosition(glm::vec3(0,10,15));
    nodeSphere->setPosition(glm::vec3(5,20,-5));
    nodeCube->bindObject(cube);
    nodeSphere->bindObject(sphere);
    // 设置相机
    String cameraName("cam1");
    Camera* camera = scnMgr->createCamera(cameraName);
    AbstractObject* obj = camera;
    SceneNode* camNode = scene->getSceneNodeRoot()->createChildSceneNode(cameraName);
    camNode->setPosition(glm::vec3(0, 0, 15));
    camNode->bindObject(camera);
    // 设置光源
    Light* light = scnMgr->createLight("mainLight");
    SceneNode* lightNode = scene->getSceneNodeRoot()->createChildSceneNode("mainLight");
    lightNode->setPosition(glm::vec3(0, 10, 15));
    lightNode->bindObject(light);
    return scene;
}

int main() {
    PrimalDawnBites::ApplicationContext ctx("sample_0");
    ctx.initApp();
    engine = ctx.getEngine();
    Scene* sample0(createTestScene());
    engine->getSceneManager()->loadScene(sample0);
    ctx.getEngine()->startRendering();
    ctx.closeApp();
    return 0;
}