#pragma once

#include <cstdint>

namespace primaldawn::utils {
	class PdEntity;

	class PdEntityManager {
	public:
		PdEntityManager();

		void Create(int num, PdEntity* entity);

		void Destroy(int num, PdEntity* entity) noexcept;
	private:
		uint32_t current_index_ = 1;
	};
}
