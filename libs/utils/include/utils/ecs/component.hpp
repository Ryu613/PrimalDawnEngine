#pragma once

#include <cstdint>

namespace utils::ecs {
	class Component {
	public:
		using IdType = uint32_t;
		Component() = default;
	private:
		friend class EntityManager;

		Component(IdType id) : id_(id) {}
		~Component();

		IdType id_{ 0 };

	};
} // namespace utils::ecs
