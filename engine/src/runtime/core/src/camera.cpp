#include "camera.hpp"
#include "viewport.hpp"
#include "scene_manager.hpp"

namespace PrimalDawn {
    Camera::Camera(const std::string& name, SceneManager* sm) 
        : mSceneManager{0} {
        mSceneManager = sm;
    }
    //void Camera::_renderScene(Viewport* vp) {
    //    mSceneManager->_renderScene(this, vp);
    //}
}