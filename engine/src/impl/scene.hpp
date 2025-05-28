#pragma once

#include "primaldawn/scene.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdScene : public Scene {
	public:
		explicit PdScene(PdEngine& engine);
		~PdScene() = default;
	private:
		PdEngine& engine_;
	};

	DOWNCAST(Scene);

} // namespace primaldawn
