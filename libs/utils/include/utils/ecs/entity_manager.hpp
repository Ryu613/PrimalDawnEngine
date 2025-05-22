#pragma once

#include <memory>

#include "utils/ecs/entity.hpp"
#include "utils/ecs/component.hpp"

namespace utils::ecs {
	class EntityManagerImpl;
	/*
	* @brief manage entity/component/instance relations and lifecycles
	* 
	* function names explained what it does
	*/
	class EntityManager {
	public:
		static EntityManager& GetSingleton();
		// cannot copy & move;
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;
		EntityManager(EntityManager&&) noexcept = delete;
		EntityManager& operator=(EntityManager&&) noexcept = delete;
		

		// create a new Entity with generated id
		Entity CreateEntity(Entity e = Entity{});

		void DestroyEntity(const Entity& e);

		void AddComponentToEntity(const Entity& e, const Component& c);

		void RemoveComponentFromEntity(const Entity& e, const Component& c);

		bool EntityHasComponent(const Entity& e, const Component& c);

	private:
		EntityManager();
		~EntityManager();

		std::unique_ptr<EntityManagerImpl> impl_;

	};
} // namespace utils::ecs
