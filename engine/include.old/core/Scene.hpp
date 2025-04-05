#pragma once

namespace pd {
    class Engine;

    class Scene {
    public:
        Scene(const Engine& engine);
        ~Scene();
    private:
        const Engine& mEngine;
    };
}
