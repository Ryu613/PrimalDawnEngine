#pragma once

#include <cstdint>

namespace utils::ecs {
	class Entity {
	public:
		using IdType = uint32_t;
		Entity() : id_(0) {}

		bool isNull() const noexcept {
			return id_ == 0;
		}
	private:
		friend class EntityManager;
		friend class EntityManagerImpl;
		Entity(IdType id) : id_(id){}
		IdType id_{ 0 };
	};
} // namespace utils::ecs
