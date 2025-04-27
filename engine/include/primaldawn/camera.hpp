#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {
	/**
	* @brief camera class specifies camera's properties
	* camera should be created by Engine.CreateCamera()
	*/
	class Camera : public Api {
	public:
	protected:
		~Camera() = default;
	};
} // namespace primaldawn
