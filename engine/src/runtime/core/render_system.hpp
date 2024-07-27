#pragma once

namespace PrimalDawn {
	class RenderSystem {
	public:
		RenderSystem();
		~RenderSystem();
		void init();
	private:
		void _createRenderWindow();
	};
}