#pragma once

#include "primaldawn/renderer.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdEngine;
	class PdView;
	class PdRenderer : public Renderer {
	public:
		explicit PdRenderer(PdEngine& engine);
		~PdRenderer() noexcept;

		PdEngine& GetEngine() const noexcept {
			return engine_;
		}

		void Render(const PdView* view);
	private:
		PdEngine& engine_;
	};

	DOWNCAST(Renderer);
} // namespace primaldawn
