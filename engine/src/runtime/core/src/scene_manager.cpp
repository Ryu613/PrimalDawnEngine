#include "scene_manager.hpp"
#include "camera.hpp"
#include "viewport.hpp"
#include "builtin_factories.hpp"

namespace PrimalDawn {

	void SceneManager::loadScene(Scene* scene) {
		LOG_INFO("¶ÁÈ¡³¡¾°[" + scene->getName() + "]...")
	}

	void SceneManager::unloadScene() {

	}

	Entity* SceneManager::createEntity(enum ENTITY_TYPE entityType) {
		return EntityFactory::createPrimitive(entityType);
	}

	//void SceneManager::_renderScene(Camera* camera, Viewport* vp) {
	//	_renderVisibleObjects();
	//}

	//void SceneManager::_renderVisibleObjects() {
	//	//_renderQueueGroupObjects();
	//}
}