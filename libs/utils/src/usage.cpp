#include "utils/ecs/ecs.hpp"

#include <string>
using namespace utils;

struct Position {
    int x, y, z;
};

struct Attr {
    std::string name;
    int hp;
};

class MoveSystem : ecs::System<MoveSystem> {
    //void OnUpdate() {
    //    for (auto& each : ecs::query<Position, Attr>()) {
    //        each.x += 2;
    //    }
    //}
};

struct Extra {

};

struct Another {
    std::string str;
};

int main() {
    ecs::init();
    ecs::Entity e = ecs::make_entity<Position, Attr>(
        Position{ 50,24,12 },
        Attr{ "john", 100 }
    );
    // add Position & Attr component data to e
    ecs::add_component_data<Position, Attr>(e, Position{ 20,10,20 }, Attr{ "mary", 105 });
    // add Position component data to e
    ecs::add_component_data<Position>(e, Position{ 20, 10, 20 });
    // error! Extra is not exist in e
    ecs::add_component_data<Extra>(e, Extra{});
    // add new component(empty data) to e
    ecs::add_component<Extra>(e, Extra{});
    // error! Position is exist in e
    ecs::add_component<Position, Another>(e, Position{ 20,40,20 }, Another{ "tehe" });
    // add new component Another to e
    ecs::add_component<Another>(e, { "tehe" });
    // true
    ecs::has_components<Attr>(e);
    // remove Another component from e
    ecs::remove_components<Another>(e);
    // remove Another component from All, is it necessary?
    //ecs::remove_component_all<Another>();
    // destroy entity e
    ecs::destroy_entity(e);
    // register new system and enable it
    // can add stage & priority in the future
    ecs::register_system<MoveSystem>();
    // trigger specific system's OnUpdate();
    ecs::system_update<MoveSystem>();
    // trigger registered systems' OnUpdate() in order
    ecs::system_update_all();
    // disable system not unregister
    ecs::disable_system<MoveSystem>();
    // re-enable system
    ecs::enable_system<MoveSystem>();
    // unregister system
    //ecs::unregister_system<MoveSystem>();
}
