# ECS调研记录

> 自我提醒：简明扼要

## 什么是ECS

ECS就是Entity/Component/System的首字母缩写，是面向数据编程(DOP)下的一种架构模式(architectural pattern)

也可称为Entity Systems(实体系统)即ES, 有些文献里把System换做Processor，觉得表述更准确

区别于OOP的数据和处理逻辑放在一起的代码编写风格，DOP是数据与逻辑分离的风格，两种风格各有用处，应用场景不同

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

> ECS一般不会用作主要编程范式，而是在OOP范式下作为补充，专门用来满足上述场景下的需求，而且性能方面，主要是对数据进行合理组织才会好，而且不一定比OOP高

## 相关应用

ECS现在已在众多领域使用，尤其是游戏引擎，或实时图形引擎

在此只列出有价值，并且我打算参考的部分

## 简介

ECS一般在实际设计中，对于Component的数据如何组织和存储，有两种思路:
- `archetype`: 也叫prototype, 中文常称为原型, Unity采用此种方式实现ECS
- `sparse sets`：也叫packed array，中文常称为稀疏集，EnTT主要采用此方式实现ECS

## 对比

### 基于archetype的ECS

#### 思路

1. 把component按组看成一个archetype, 查询某个entity有没有组件时，是根据archetype去找，能提高查询效率
1. archetype内部的组件数据就是用SOA结构存储的,archetype在unity里还进一步区分出chunk，方便并行处理

优点:
1. 多线程友好，可将archetype分发给不同线程处理
1. archetype数据布局局部性好，有利于缓存命中，提高性能
1. 遍历效率高，只需按照archetype来遍历，数量远少于entity

缺点:
1. 实体要改变包含的组件时，要移动archetype，有开销
1. 组件的组合太多样的话，archetype就会很多，也会降低查询效率
1. archetype视作是同一优先级的，遍历时很可能把那些不太重要的archetype也遍历一次

### 基于sparse set的ECS

#### 思路

1. 由system持有Entity,用sparse set维护entity和component的关系，system要注册到一个统一的管理器里，这个管理器负责执行系统，管理实体和组件
1. 由system持有Component的类型和实例，一个Component只能由一个system持有，其他系统只能引用，上面提到的管理器就不需要了

### EnTT： 一个用现代C++实现的知名开源ECS库

> 版本: 

利用稀疏集组织Component的数据以提高性能

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

### 其他参考

1. [Unity中的ECS](https://docs.unity3d.com/Packages/com.unity.entities@1.4/manual/concepts-intro.html)
1. [EntityX:知名ECS库](https://github.com/alecthomas/entityx)
1. [Flecs:另一个比较有名的开源ECS库](https://github.com/SanderMertens/flecs)

## 参考资料

1. [漫谈ECS](https://skypjack.github.io/2019-02-14-ecs-baf-part-1/)
1. [游戏中的编程模式](https://gameprogrammingpatterns.com/)
1. [ECS的组件设计、内存布局和系统调度的详细解析](https://gamesfromwithin.com/data-oriented-design)
1. [稀疏集](https://manenko.com/2021/05/23/sparse-sets.html)
