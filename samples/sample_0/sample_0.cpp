#include "application_context.hpp"
#include "entity.hpp"
#include "scene_node.hpp"

PrimalDawn::Engine* engine = nullptr;

PrimalDawn::Scene* createTestScene() {
    using namespace PrimalDawn;
    Scene* scene = new Scene();
    // 创建1个球一个立方体，设置好材质后放到场景里
    Entity* sphere = engine->getSceneManager()->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_SPHERE);
    Entity* cube = engine->getSceneManager()->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_CUBE);
    // 创建场景节点并关联物体
    SceneNode* nodeCube = scene->getSceneNodeRoot()->createChildSceneNode();
    SceneNode* nodeSphere = scene->getSceneNodeRoot()->createChildSceneNode();
    // 为2个实体设置位置和方向
    nodeCube->setPosition(glm::vec3(0,10,15));
    nodeSphere->setPosition(glm::vec3(5,20,-5));
    nodeCube->bindObject(cube);
    nodeSphere->bindObject(sphere);
    // 设置相机，光源


    return scene;
}

int main() {
    PrimalDawnBites::ApplicationContext ctx("sample_0");
    ctx.initApp();
    engine = ctx.getEngine();
    PrimalDawn::Scene* sample0(createTestScene());
    engine->getSceneManager()->loadScene(sample0);
    ctx.getEngine()->startRendering();
    ctx.closeApp();
    return 0;
}