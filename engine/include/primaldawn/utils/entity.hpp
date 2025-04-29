#pragma once

#include <cstdint>

namespace primaldawn::utils {
	/*
	* @ brief An Entity is a wrapper for scene objects
	*/
	class Entity {
	public:
		// entities can be compared, sorted
		bool operator==(Entity e) const;

		bool operator!=(Entity e) const;

		bool operator<(Entity e) const;

		bool isNull() const noexcept;

		explicit operator bool() const noexcept;

		uint32_t GetId() const noexcept;
	protected:
		Entity() = default;
		~Entity() = default;
	};
} // namepsace primaldawn::utils
