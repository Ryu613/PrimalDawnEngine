#include "application_context.hpp"

int main() {
    PrimalDawnBites::ApplicationContext ctx("sandbox");
    ctx.initApp();
   
    ctx.getEngine()->startRendering();
    ctx.closeApp();
    return 0;
}