#pragma once

#include "primaldawn/config.hpp"

namespace primaldawn {
	/**
	* 渲染系统主类，对各种图形API做抽象
	*/
	class PdRenderSystem {
	public:
		explicit PdRenderSystem(config::RenderSystem config);
		virtual ~PdRenderSystem();

		virtual void bindPipeline();
		virtual void draw();

	protected:
		config::RenderSystem config_;
	};

} // namespace primaldawn
