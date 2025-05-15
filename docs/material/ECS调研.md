# ECS调研记录

> 自我提醒：简明扼要

## 什么是ECS

ECS就是Entity/Component/System的首字母缩写，是面向数据编程(DOP)下的一种代码编写范式

区别于OOP的数据和处理逻辑放在一起的代码编写风格，DOP是数据与逻辑分离的风格，两种风格各有用处，不存在孰高孰低，只是应用场景不同

- `E`: 代表某个对象实例，有一个唯一id，包含若干C
- `C`: 用来描述E包含的一部分数据的统称，C又由与其相关的若干数据组成
- `S`: 代表对若干C的处理逻辑，通常来说，只关心C，与E没有直接关系

最简例子如下:
```c++

// PlayerEntity代表玩家这种事物，其包含位置，属性的相关数据
PlayerEntity(MoveComponent, AttrComponent)

// MoveComponent包含一组坐标数据
MoveComponent(x,y,z)

// AttrComponent也包含血量，魔量数据
AttrComponent(hp,mp)

// 现在有一个MoveSystem,主要是对含有PositionComponent的所有Entity更新位置信息,进行移动，伪代码如下:
// 这个MoveSystem并不关心是哪种Entity，只关心MoveComponent
for(每个MoveComponent : 所有MoveComponent) {
    每个MoveComponent.x += 1;
    每个MoveComponent.y += 1;
    每个MoveComponent.z += 1;
}

// 如果是基于OOP的思路，那么伪代码类似下面的例子:

for(每个对象 : 所有实现了Move接口的对象) {
    每个对象.move(1,1,1);
}

```
## 为什么这么做

1. 利于并行
    - 数据按同种类型组织，处理逻辑也是类似且数据互不干扰，方便把执行过程拆细，利于多线程化
1. 利于缓存    
    - 把Component拆分后，利于数据组成更紧凑连续的结构，System只关心Component, 对数据的读写友好，利于内存连续和局部性，利于缓存命中，最终利于提高性能
1. 利于修改
    - Entity可自由组织Component,更灵活，对entity和component的修改很方便，如果是OOP可能就要对很多对象进行修改
1. 利于测试
    - 面向对象时，需要mock，DOP时，只用创建一组数据，调用system，然后看输出的数据是否符合期望即可

## 解决了什么问题

ECS用于改善以下场景出现的代码难以维护，难以扩展的问题，其次是性能低的问题:

1. 对象包含的数据很多，处理逻辑很多，对象的实例很多，对象的横向或纵向关系复杂时
1. 数据处理频繁，性能要求高

> ECS一般不会用作主要编程范式，而是在OOP范式下作为补充，专门用来满足上述场景下的需求，而其他场景下，很可能性能不一定比OOP高

## 相关应用

ECS现在已在众多领域使用，尤其是游戏引擎，或实时图形引擎

在此只列出有价值，并且我打算参考的部分

### EnTT： 一个用现代C++实现的知名开源ECS库

> 版本: 

### Filament的ECS实现

> 版本: v1.58.0

ECS相关代码实现位于libs/utils下，相关类包括:
- Entity.h: 只有一个id，可表示Entity和Component，可以为空(id=0)
- EntityInstance.h, 表示Entity的实例
- EntityManager.h, 管理Entity的生命周期，创建，销毁
- EntityManagerImpl.h, EntityManager的实现类
- SingleInstanceComponentManager.h: 把组件看成一个instance，还管理entity和这个instance的关系，component都存在SOA里
- StructureOfArrays.h: 一个数组，里面存了各类Component，和这个instance的id(用entity表示)，还有分配器也传进去了，方便进行内存管理

这个ECS模型的S是各类Manager，比如RenderableManager等，这种实现不是标准的ECS，但是看起来比较灵活，使用方式是把
SingleInstanceComponentManager看作某个Manager的成员，用模板参数定义出各个Component的数据，然后继承此类方便具体操作，实现还是比较灵活的，但是我觉得不容易理解和使用

比如在RenderableManager中，可把此Manager看作是一个System，即RenderableSystem,这个类要管理的就是RenderableEntity,代码里就当场定义出来，代码如下:
```c++
    // 等效于定义Renderable这个Entity包含的Component做声明
    enum {
        AABB,                   // user data
        LAYERS,                 // user data
        MORPH_WEIGHTS,          // filament data, UBO storing a pointer to the morph weights information
        CHANNELS,               // user data
        INSTANCES,              // user data
        VISIBILITY,             // user data
        PRIMITIVES,             // user data
        BONES,                  // filament data, UBO storing a pointer to the bones information
        MORPHTARGET_BUFFER,     // morphtarget buffer for the component
        DESCRIPTOR_SET          // per-renderable descriptor set
    };
    // 等效于为这些Component声明数据的类型,
    using Base = utils::SingleInstanceComponentManager<
            Box,                             // AABB
            uint8_t,                         // LAYERS
            MorphWeights,                    // MORPH_WEIGHTS
            uint8_t,                         // CHANNELS
            InstancesInfo,                   // INSTANCES
            Visibility,                      // VISIBILITY
            utils::Slice<FRenderPrimitive>,  // PRIMITIVES
            Bones,                           // BONES
            FMorphTargetBuffer*,            // MORPHTARGET_BUFFER
            DescriptorSet          // DESCRIPTOR_SET
    >;
    // 等效于Entity对应了Base这个由多个Component组成的instance
    // 里面有个proxy方便对其进行操作，进行参数实例化，用了union结构体来省内存
    struct Sim : public Base {
        using Base::gc;
        using Base::swap;

        struct Proxy {
            // all of this gets inlined
            UTILS_ALWAYS_INLINE
            Proxy(Base& sim, utils::EntityInstanceBase::Type i) noexcept
                    : aabb{ sim, i } { }

            union {
                // this specific usage of union is permitted. All fields are identical
                Field<AABB>                 aabb;
                Field<LAYERS>               layers;
                Field<MORPH_WEIGHTS>        morphWeights;
                Field<CHANNELS>             channels;
                Field<INSTANCES>            instances;
                Field<VISIBILITY>           visibility;
                Field<PRIMITIVES>           primitives;
                Field<BONES>                bones;
                Field<MORPHTARGET_BUFFER>   morphTargetBuffer;
                Field<DESCRIPTOR_SET>       descriptorSet;
            };
        };

        UTILS_ALWAYS_INLINE Proxy operator[](Instance i) noexcept {
            return { *this, i };
        }
        UTILS_ALWAYS_INLINE const Proxy operator[](Instance i) const noexcept {
            return { const_cast<Sim&>(*this), i };
        }
    };

    Sim mManager;
```
这种方式实现非常灵活，可在任意地方自行声明ECS之间的关系，内部数据是由SOA组织，SOA就是一个用std::tuple实现的数据集合，里面存了某一个entity的所有component的数据，还包含了一个id和分配器，方便对其进行gc

这个代码实现确实灵活，不过需要额外学习成本，因为不是标准ECS模式

### 其他参考

1. [Unity中的ECS](https://docs.unity3d.com/Packages/com.unity.entities@1.4/manual/concepts-intro.html)
1. [Flecs:另一个比较有名的开源ECS库](https://github.com/SanderMertens/flecs)

## 参考资料

1. [ECS的前前后后](https://skypjack.github.io/2019-02-14-ecs-baf-part-1/)
1. [游戏中的编程模式](https://gameprogrammingpatterns.com/)
1. [ECS的组件设计、内存布局和系统调度的详细解析](https://gamesfromwithin.com/data-oriented-design)
