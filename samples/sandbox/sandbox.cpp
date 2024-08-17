#include "application_context.hpp"

int main() {
    PrimalDawnBites::ApplicationContext ctx("sandbox");
    ctx.initApp();
    PrimalDawn::Engine* engine = ctx.getEngine();
    PrimalDawn::SceneManager* sceneManager = engine->createSceneManager();
    ctx.getEngine()->startRendering();
    ctx.closeApp();
    return 0;
}