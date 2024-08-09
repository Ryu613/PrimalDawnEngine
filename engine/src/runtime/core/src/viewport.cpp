#include "viewport.hpp"
#include "camera.hpp"

namespace PrimalDawn {
    void Viewport::update() {
        if (mCamera) {
            mCamera->_renderScene(this);
        }
    }
}