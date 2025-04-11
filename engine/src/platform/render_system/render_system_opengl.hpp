#pragma once

#include "impl/render_system.hpp"

namespace primaldawn {
	class RenderSystemOpenGL : public PdRenderSystem {
	public:
		explicit RenderSystemOpenGL(config::RenderSystem config);
		~RenderSystemOpenGL();

		void BindPipeline() override;
		void Draw() override;
	private:
	};
} // namespace primaldawn
