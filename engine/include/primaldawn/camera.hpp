#pragma once

#include "primaldawn/api.hpp"

#include <cstdint>

namespace primaldawn {
	/**
	* @brief camera class specifies camera's properties
	* camera should be created by Engine.CreateCamera()
	*/
	class Camera : public Api {
	public:
		enum class Projection : uint8_t {
			PERSPECTIVE = 1,
			ORTHOGRAPHIC = 2,
		};
		enum class Fov : uint8_t {
			VERTICAL = 1,
			HORIZONTAL = 2,
		};
	protected:
		~Camera() = default;
	};
} // namespace primaldawn
