#pragma once

#include <memory>

namespace primaldawn {
	class RenderTarget;
	/**
	* @brief 封装每一帧的数据
	*/
	class RenderFrame {
	public:
		explicit RenderFrame(const RenderContext& render_context);
	private:
		const RenderContext& render_context_;
		std::unique_ptr<RenderTarget> render_target_;
	};
} // namespace primaldawn
