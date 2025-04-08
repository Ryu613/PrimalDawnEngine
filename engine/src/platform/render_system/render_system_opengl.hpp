#pragma once

#include "impl/render_system.hpp"

namespace primaldawn {
	class RenderSystemOpenGL : public PdRenderSystem {
	public:
		explicit RenderSystemOpenGL(config::RenderSystem config);
		~RenderSystemOpenGL();

		void bindPipeline() override;
		void draw() override;
	private:
	};
}
