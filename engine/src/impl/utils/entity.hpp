#pragma once

#include "primaldawn/utils/entity.hpp"

#include <cstdint>

#include "downcast.hpp"

namespace primaldawn::utils {
	class PdEntity : public Entity {
	public:
		// construct empty entity
		PdEntity() noexcept {};
		
		// entities can be compared, sorted
		bool operator==(PdEntity e) const {
			return e.id_ == id_;
		}

		bool operator!=(PdEntity e) const {
			return e.id_ != id_;
		}

		bool operator<(PdEntity e) const {
			return e.id_ < id_;
		}

		bool isNull() const noexcept {
			return id_ == 0;
		}

		explicit operator bool() const noexcept {
			return !isNull();
		}

		uint32_t GetId() const noexcept {
			return id_;
		}
	private:
		friend class PdEntityManager;

		explicit PdEntity(uint32_t index = 0U)
			: id_(index) {
		};

		uint32_t id_ = 0;
	};

	DOWNCAST(Entity)
}
