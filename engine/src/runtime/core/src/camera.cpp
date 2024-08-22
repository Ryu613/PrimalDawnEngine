#include "camera.hpp"
#include "scene.hpp"

namespace PrimalDawn {
    Camera::Camera() {

    }

    Camera::~Camera() {

    }

    Camera::Camera(const String& name, Scene* scene) 
        : mScene{NULL} {
        mScene = scene;
    }
    //void Camera::_renderScene(Viewport* vp) {
    //    mSceneManager->_renderScene(this, vp);
    //}
}