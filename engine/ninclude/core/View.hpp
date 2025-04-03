#pragma once

namespace pd {
	class View {
	public:
		View(const Scene& scene, const Camera& camera);
		~View();
	private:
		const Scene& mScene;
		const Camera& mCamera;
	};
}
