#include <iostream>
#include <exception>

#include "application/application.hpp"

using namespace primaldawn;

int main() {
    ApplicationConfig config{
        .app_name = "triangle",
    };
    auto& app = Application::Get();
    try {
        app.Configure(&config)
           .SetupScene()
           .Run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        return -1;
    }
    return 0;
}
