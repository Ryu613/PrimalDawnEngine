#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {
	class Scene;
	class Camera;
	class View : public Api {
	public:
		void SetScene(Scene* scene);
		Scene* GetScene() noexcept;
		void SetCamera(Camera* camera) noexcept;
		Camera& GetCamera() noexcept;
	protected:
		~View() = default;
	};
} // namespace primaldawn
