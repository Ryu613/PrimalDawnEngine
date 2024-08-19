#include "application_context.hpp"

PrimalDawn::Scene* createTestScene() {
    return new PrimalDawn::Scene();
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