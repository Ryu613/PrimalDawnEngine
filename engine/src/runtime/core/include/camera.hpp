#pragma once
#include <string>

namespace PrimalDawn {
    class Viewport;
    class SceneManager;
    class Camera {
    public:
        Camera(const std::string& name, SceneManager* sm);
        void _renderScene(Viewport* vp);
    protected:
        SceneManager* mSceneManager;
    private:
        float mPixelDisplayRatio;
    };
} 