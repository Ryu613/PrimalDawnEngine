#pragma once

#include "primaldawn/renderer.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdEngine;

	class PdRenderer : public Renderer {
	public:
		explicit PdRenderer(const PdEngine& engine);
		~PdRenderer() noexcept;

		void render();
	private:
		const PdEngine& engine_;
	};

	DOWNCAST(Renderer);
} // namespace primaldawn
