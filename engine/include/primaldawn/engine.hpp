#pragma once

#include <memory>

#include "primaldawn/config.hpp"

namespace primaldawn {
    class Scene;
    class View;
    class Camera;
    /**
    * @brief Engine is Main entry of whole system, provide global management api of subsystems 
    * Engine should be created by Create(), and destroy by Destroy();
    */
	class Engine {
	public:

        /**
        * @brief create Engine, if no config specified, then use default config
        * 
        * Engine's lifetime should be management by Application, if using Engine directly, keep in mind that
        * every Engine instance should close correctly by calling Destroy()
        * 
        * @return Engine pointer use Destroy(Engine* engine)
        */
        static Engine* Create(const config::Engine* config = nullptr) noexcept;

        /**
        * @brief destroy engine
        */
        static void Destroy(Engine* engine);

        /**
        * @brief start rendering a scene
        */
        void Run();

        /**
        * @brief create a scene
        */
        Scene* CreateScene() noexcept;

        /**
        * @brief create a view
        */
        View* CreateView() noexcept;

        /**
        * @brief create a camera
        * 
        */
        Camera* CreateCamera() noexcept;
        
        /**
        * @brief detect whether the engine is running
        */
        inline bool IsRunning() const;

    protected:
        // this is interface class, cannot construct directly
        Engine() noexcept = default;
        ~Engine() = default;

    public:
        // copy & assignment & move not supported, Engine holder cannot pass ownership
        // delete unnecessary ctor
        Engine(const Engine&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(Engine&&) = delete;
	};

} // namespace primaldawn
