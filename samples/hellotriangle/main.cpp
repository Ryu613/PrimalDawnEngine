#include "HelloTriangle.h"

using namespace pd;

int main() {
    HelloTriangle app;
    AppConfig config;
    app.prepare(config);
    app.run();
    app.close();
}
