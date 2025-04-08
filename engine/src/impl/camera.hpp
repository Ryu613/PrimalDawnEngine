#pragma once

#include "primaldawn/camera.hpp"

#include "downcast.hpp"

namespace primaldawn {
	/**
	* 相机是基于物理的
	*/
	class PdCamera : public Camera {
	private:

	};

	DOWNCAST(Camera);
}
