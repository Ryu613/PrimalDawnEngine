#pragma once

namespace pd {
    class Engine;
    class Scene {
    public:
        Scene(Engine& engine);
        ~Scene() noexcept;
    private:
        Engine& mEngine;
    };
}
