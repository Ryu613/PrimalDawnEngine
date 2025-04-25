#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {
	/**
	* @brief 相机相关操作
	*
	* 相机应从Engine.CreateCamera()构建
	*/
	class Camera : public Api {
	public:
	protected:
		~Camera() = default;
	};
} // namespace primaldawn
