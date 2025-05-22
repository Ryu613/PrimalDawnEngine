# ECS设计

## 总体设计

本版设计考虑的优先级为: 功能 > 性能 > 空间

对经典ECS架构进行改进，故ECS并不直接对应到这三种class，本版暂不考虑多线程环境和事件监听，但是预留了扩展性

- `Identity`: 有id, name, 用于标记和识别信息，可当作Entity, Component,EntityInstance，这么做可减少数据存储多份副本
- `SOA`: 以数组形式存储同类型数据，是一个类模板，可设定内存分配器，同时还保存了component的实际数据，还提供了SOA数据的访问
- `EntityManager`: 负责维护e/c, e/i关系，生命周期，创建/销毁Entity, 添加/删除Component, 还可以根据Component和字段名改数据
- `register`: 在EntityManager内部，有个id生成器，还有记录了可复用的id集合，里面是2个bitset数组,有E/C的增删函数
- `sparse_set`: 在register内部，用来维护E/C和C位置关系，查询E是否有C，若有，这个C在SOA里的下标是多少，此结构的查询和增删算法复杂度都为O(1),效率极高 

没有直接的system，system就是各个manager，一个manager对应一个或多个entity

## 使用

例如，有个类是RenderableManager,那么使用这个ECS例子如下:

```c++
// 一般是单例的
class RenderableManager {
public:
    // 一些getter/setter,其实是调用EntityManager的对应函数来做获取和设置
    ...
    // 构造器，实现里可以把这个EntityManager按照你要求的Entity和Component关系构造出来
    RenderableManager();
    void OnUpdate();
private:
    Entity renderableEntity;
}
...
// 构造方法
RenderableManager() {
    const auto& mgr = EntityManager::get();
    renderable = mgr.createEntity<int, Box, Layer>("height", "Box", "Layer");
}
...
// 更新方法
void OnUpdate() {
     const auto& mgr = EntityManager::get();
     int addHeight = 5;
     auto setHeight = [addHeight](int& height){height += addheight};
     mgr.setComponentData<renderable>("height", setHeight);
}

```

## 实现

参考libs/ecs

## 参考资料

1. [自己的ECS调研记录](../material/ECS调研.md)
