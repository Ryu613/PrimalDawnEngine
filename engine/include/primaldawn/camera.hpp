#pragma once

namespace primaldawn {
	/**
	* @brief 相机相关操作
	*
	* 相机应从Engine.CreateCamera()构建
	*/
	class Camera {
	public:
	protected:
		Camera() = default;
		~Camera() = default;
	public:
		Camera(const Camera&) = delete;
		Camera& operator=(const Camera&) = delete;
		Camera(Camera&&) = delete;
		Camera& operator=(Camera&&) = delete;
	};
} // namespace primaldawn
