#include "application_context.hpp"
#include "entity.hpp"
#include "scene_node.hpp"

PrimalDawn::Engine* engine = nullptr;

PrimalDawn::Scene* createTestScene() {
    using namespace PrimalDawn;
    Scene* scene = new Scene();
    // ����1����һ�������壬���úò��ʺ�ŵ�������
    Entity* sphere = engine->getSceneManager()->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_SPHERE);
    Entity* cube = engine->getSceneManager()->createEntity(ENTITY_TYPE::PRIMITIVE_TYPE_CUBE);
    // ���������ڵ㲢��������
    SceneNode* nodeCube = scene->getSceneNodeRoot()->createChildSceneNode();
    SceneNode* nodeSphere = scene->getSceneNodeRoot()->createChildSceneNode();
    // Ϊ2��ʵ������λ�úͷ���
    nodeCube->setPosition(glm::vec3(0,10,15));
    nodeSphere->setPosition(glm::vec3(5,20,-5));
    nodeCube->bindObject(cube);
    nodeSphere->bindObject(sphere);
    // �����������Դ


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