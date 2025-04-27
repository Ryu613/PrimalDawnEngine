#pragma once

#include "primaldawn/renderer.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdEngine;

	class PdRenderer : public Renderer {
	public:
		explicit PdRenderer(const PdEngine& engine);
		~PdRenderer() noexcept;

		const PdEngine& GetEngine() const noexcept {
			return engine_;
		}

		void Render(const PdView* view);
	private:
		const PdEngine& engine_;
	};

	DOWNCAST(Renderer);
} // namespace primaldawn
