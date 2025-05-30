# 设计决策

此处记录设计思考

## 设计目标

轻量级实时PBR图形渲染引擎

## 开发环境

windows 10 + VS2022 + CMake(3.27) + C++20

### 项目要求

1. 目录简单清晰，尽量一看就懂
1. 文档较为健全，采用markdown + doxygen
1. 注释用英文，文档中英文都会有视情况而定
1. 代码风格参考google C++ code style, 除了文件名后缀使用hpp, cpp，头文件header guard用pragma once,用.editorconfig做简单的代码格式规定
1. 第三方库管理统一采用fetchcontent, 文档统一用doxygen，文档格式主要是markdown
1. 引擎模块化，内外分离
1. 为避免推进过于缓慢，降低设计和实现心智负担，权衡开发速度和质量，性能考虑适可而止，本阶段非必须不优化
1. 暂不考虑支持测试框架或测试包的兼容，用samples样例测试即可

## 架构设计

核心类可参考engine/include/primaldawn

整个系统分为核心层(底层或通用功能)，平台层(操作系统，底层API封装，窗口系统等)，资源层(ECS)

Engine类是整个引擎涉及所有子系统的聚合类，也是整个引擎的入口，对外只暴露include/primaldawn下接口

libs用于方便engine使用的库，或者可从engine独立出来的库

## 公开接口

- engine: 引擎操作
- config: 各种配置
- platform: 平台操作
- enums: 枚举
- scene: 场景配置
- view: 视窗配置
- camera: 相机配置
- renderer: 渲染器

## 子模块设计

1. [内存分配方案](design/内存分配方案.md)
1. [ECS设计](design/ECS设计.md)
1. [RHI设计](design/RHI设计.md)
1. [PBR设计](design/PBR设计.md)
1. [RenderGraph设计](design/RenderGraph设计.md)
1. [JobSystem设计](design/JobSystem设计.md)

## 核心调用链

### 初始化过程

Application -> Engine -> Platform -> WindowSystem -> RenderSystem -> Renderer

### 核心运行过程

Application.Run() -> Engine.Run() -> Renderer.Render() -> (loop)RenderSystem.Draw()

## 使用

一般只需继承libs下的application类即可完成大部分功能，用户只需关注include/primaldawn下的接口即可

## 本地库

- utils: 内存分配器，pimpl等各种工具或helper
- ecs: ecs框架
- application: 对engine做了轻量封装，方便使用

## 三方库

- glm: 常用线性代数操作库
- glfw3/sdl2 : 常用跨平台窗口系统
- spdlog: 主流高性能日志操作库
- imgui: 高性能界面绘制

## 其他

### 待调研

- boost/folly/openMP
- 依赖注入
- graphviz
- tracy, renderdoc
- 其他调试工具
