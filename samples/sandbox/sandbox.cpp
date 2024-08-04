#include "application_context.hpp"
#include <iostream>

int main() {
    PrimalDawnBites::ApplicationContext ctx("sandbox");
    ctx.initApp();
    std::cout << "good";
}