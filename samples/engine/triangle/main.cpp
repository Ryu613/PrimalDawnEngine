#include <iostream>
#include <exception>

#include "application/application.hpp"
#include "utils/ecs/ecs.hpp"

using namespace primaldawn;
using namespace utils;

struct Position {
    int x, y, z;
};

struct Attr {
    std::string name;
    int hp;
};

int main() {

    ecs::init();
    ecs::Entity e = ecs::make_entity<Position, Attr>(
        Position{ 50,24,12 },
        Attr{ "john", 100 }
    );
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
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
