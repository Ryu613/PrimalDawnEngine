#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {

	/**
	* @brief scene contains object and light instances
	* Scene is created from Engine.CreateScene()
	*/
	class Scene : public Api {
	protected:
		~Scene() = default;
	};
} // namespace primaldawn
