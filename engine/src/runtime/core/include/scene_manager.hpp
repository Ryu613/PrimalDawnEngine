#pragma once

namespace PrimalDawn {
    class Camera;
    class Viewport;
    class SceneManager {
    public:
        virtual void _renderScene(Camera* camera, Viewport* vp);
        void _renderVisibleObjects();
    };
}