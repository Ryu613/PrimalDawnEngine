#include "scene_manager.hpp"
#include "macro.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "scene.hpp"
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

	Scene* SceneManager::createScene(const String& sceneName) {
		Scene* scene = new Scene();
		return scene;
	}

	Camera* SceneManager::createCamera(const String& name) {
		return new Camera();
	}

	Light* SceneManager::createLight(const String& name) {
		return new Light();
	}

	//void SceneManager::_renderScene(Camera* camera, Viewport* vp) {
	//	_renderVisibleObjects();
	//}

	//void SceneManager::_renderVisibleObjects() {
	//	//_renderQueueGroupObjects();
	//}
}