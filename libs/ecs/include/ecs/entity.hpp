#pragma once

#include <cstdint>

namespace ecs {
	class Entity {
	public:
		// can be copy & move
		Entity(const Entity&) = default;
		Entity& operator=(const Entity&) = default;
		Entity(Entity&&) noexcept = default;
		Entity& operator=(Entity&&) noexcept = default;

		// can be compared
		bool operator==(Entity e) const {
			return e.id_ == id_;
		}
		bool operator!=(Entity e) const {
			return e.id_ = id_;
		}
		bool operator<(Entity e) const {
			return e.id_ < id_;
		}

		bool isNull() const noexcept {
			return id_ == 0;
		}

		explicit operator bool() const noexcept {
			return !isNull();
		}
	private:
		using IdType = uint32_t;
		// cannot be assign id directly, use EntityManager to operate
		explicit Entity(IdType id) noexcept : id_(id) {};
		IdType id_{0};
	};
}
