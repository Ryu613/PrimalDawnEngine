# ECS设计

## 类设计

1. `Entity`: 只有一个id，Component也算作Entity的一种        
1. `EntityManager`: 对Entity进行相关操作，也包括对其进行创建和销毁，同时维护一个Entity和Component的对应关系
1. `archetype`: 表示一组具有相同Component的对象，与Entity 1:1或n:1关系


## 参考资料

1. [自己的ECS调研记录](../material/ECS调研.md)
