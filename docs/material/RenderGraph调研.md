# RenderGraph 调研

> 自我提醒： 简明扼要，通俗易懂

## 什么是RenderGraph

Render Graph又叫Frame Graph, 是针对渲染管线涉及的资源和任务的关系进行管理的一种设计模式。

此设计模式主要用于解决以下问题：

- `资源依赖复杂`
- `同步状态复杂`
- `扩展麻烦`
- `调试困难`
- `渲染效率低`

## 核心思想

把渲染管线中的各个阶段看作一个有向无环图(DAG)

- `节点`: 代表 render pass，它自己知道需要输入哪些资源，输出哪些资源
- `有单个方向的边`: 代表资源的依赖关系，从资源的输出节点，指向资源输入的节点，没有循环依赖

把渲染过程抽象成DAG后，又分成三个阶段:

- `Setup`:准备这一帧需要的所有资源，声明这些资源，并声明要对这些资源进行的操作
- `Compile`: 形成整个图，把实际没用到的资源和节点剔除，确定资源的分配和回收时机,同步状态
- `Execute`: 形成好的图上的每个节点，开始执行

## 设计思路



## 参考资料

1. [learning Render Graph](https://yrom.net/blog/2023/08/13/learning-render-graph)
1. [Render Graph 101](https://blog.traverseresearch.nl/render-graph-101-f42646255636)
1. [why talking about render graphs](https://logins.github.io/graphics/2021/05/31/RenderGraphs.html)
1. [render graphs and vulkan](https://themaister.net/blog/2017/08/15/render-graphs-and-vulkan-a-deep-dive/)
1. [dragonjoker/render graph](https://github.com/DragonJoker/RenderGraph)
1. [gdc render graph](https://www.bilibili.com/video/BV1Vx411v7gY)
