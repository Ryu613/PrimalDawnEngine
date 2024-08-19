#include "scene_manager.hpp"
#include "camera.hpp"
#include "viewport.hpp"

namespace PrimalDawn {

	void SceneManager::loadScene(Scene* scene) {
		LOG_INFO("¶ÁÈ¡³¡¾°[" + scene->getName() + "]...")
	}

	void SceneManager::unloadScene() {

	}
	//void SceneManager::_renderScene(Camera* camera, Viewport* vp) {
	//	_renderVisibleObjects();
	//}

	//void SceneManager::_renderVisibleObjects() {
	//	//_renderQueueGroupObjects();
	//}
}