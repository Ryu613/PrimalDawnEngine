#pragma once

namespace PrimalDawn {
    class Camera;
    class Viewport {
    public:
        void update();
    private:
        Camera* mCamera;
    };
}