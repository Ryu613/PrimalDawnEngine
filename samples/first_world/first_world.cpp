#include "application_context.hpp"

PrimalDawn::Scene* createTestScene() {
    PrimalDawn::Scene* sandboxScene = new PrimalDawn::Scene();
    return sandboxScene;
}

int main() {
    PrimalDawnBites::ApplicationContext ctx("sandbox");
    ctx.initApp();
    PrimalDawn::Engine* engine = ctx.getEngine();
    PrimalDawn::Scene* sandboxScene(createTestScene());
    engine->getSceneManager()->loadScene(sandboxScene);
    ctx.getEngine()->startRendering();
    ctx.closeApp();
    return 0;
}