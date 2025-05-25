# ECS设计

## 设计哲学

尽量少抽象新概念，减少使用的学习成本，尽量不用看文档，看api就能知道怎么用

## 总体设计

### 类设计

- `ecs`: 头文件，用户只需引入此头文件即可使用ecs
- `entity`: 实体类，只有一个id
- `system`: 系统的基类模板，具体的系统需要派生其上
- `ecs_manager`: 管理entity的id和生命周期
- `archetype`: 管理component的信息和存储,archetype内部分为多个chunk

### api设计

类似std的风格，上手简单

### 存储方案

archetype + chunk

## 使用

如下所示

```c++
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

```

## 实现

参考zetools/ecs

## 参考资料

1. [自己的ECS调研记录](../material/ECS调研.md)
