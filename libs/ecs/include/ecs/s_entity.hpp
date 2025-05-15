#pragma once

#include <cstdint>

namespace ecs {
	class SEntity {
	public:
		explicit SEntity(uint32_t id) : id_(id) {};
		void addComponent(Component component);
		void removeComponent(uint32_t id);

	private:
		uint32_t id_{ 0 };
		std::vector<Component> components_;
	};
}
