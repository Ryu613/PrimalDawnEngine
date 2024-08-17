#include "scene_manager.hpp"
#include "camera.hpp"
#include "viewport.hpp"

namespace PrimalDawn {
	void SceneManager::_renderScene(Camera* camera, Viewport* vp) {
		_renderVisibleObjects();
	}

	void SceneManager::_renderVisibleObjects() {
		//_renderQueueGroupObjects();
	}
}