#pragma once

namespace ecs {
	class EntityManager {
	public:
		static EntityManager& get() noexcept;
	};
}
