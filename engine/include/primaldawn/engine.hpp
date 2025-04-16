#pragma once

#include <memory>

#include "primaldawn/config.hpp"

namespace primaldawn {
    class Scene;
    class Camera;
    /**
    * @brief Engine类是整个系统的入口，负责全局管理各个子系统的功能,也负责创建和销毁各种相关资源
    * 
    * Engine本身通过Create,Destroy管理生命周期
    * 
    * 功能:
    * 1. 资源管理
    * 2. 全局配置
    * 3. 常用功能
    * 
    * 优化点:
    * 1. 非虚，纯接口类
    * 2. 构造析构隐藏，访问控制
    * 3. 公私分离，实际实现类在PdEngine
    * 4. RAII, noexcept
    * 5. 内存分配控制
    */
	class Engine {
	public:

        /**
        * @brief 创建Engine类
        */
        static Engine* Create(config::Engine config) noexcept;

        /**
        * @brief 销毁引擎
        */
        static void Destroy(Engine* engine);

        /**
        * @brief 开始运行
        */
        void Run();

        /**
        * @brief 创建场景
        */
        Scene* CreateScene() noexcept;

        /**
        * @brief 创建相机
        */
        Camera* CreateCamera() noexcept;
        
        /**
        * @brief 当前是否在运行
        */
        inline bool IsRunning() const;

    protected:
        Engine() = default;
        ~Engine() = default;

    public:
        // 不允许移动拷贝
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(Engine&&) = delete;
	};

} // namespace primaldawn
