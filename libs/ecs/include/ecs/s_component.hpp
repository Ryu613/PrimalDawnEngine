#pragma once

#include <cstdint>

namespace ecs {
	class Component {
	public:
		explicit Component(uint32_t id) : id_(id) {};

	private:
		uint32_t id_{ 0 };
	};
}
