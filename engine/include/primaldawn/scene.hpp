#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {

	/**
	* @brief 包含所有Renderable和Light
	* 
	* 由Engine管理Scene的创建和销毁
	*/
	class Scene : public Api {
	protected:
		~Scene() = default;
	};
} // namespace primaldawn
