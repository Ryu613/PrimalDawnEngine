#pragma once

#include "primaldawn/view.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdEngine;
	class PdScene;
	class PdCamera;
	class PdView : public View {
	public:
		explicit PdView(const PdEngine& engine);
		~PdView() noexcept;

		void SetScene(PdScene* scene) {
			scene_ = scene;
		}
		PdScene* GetScene() noexcept {
			return scene_;
		}
		void SetCamera(PdCamera* camera) {
			camera_ = camera;
		}
		PdCamera& GetCamera() const {
			return *camera_;
		}

	private:
		const PdEngine& engine_;
		PdScene* scene_ = nullptr;
		PdCamera* camera_ = nullptr;
	};

	DOWNCAST(View);

} // namespace primaldawn
