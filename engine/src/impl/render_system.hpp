#pragma once

#include "primaldawn/config.hpp"

namespace primaldawn {
	/**
	* 渲染系统主类，对各种图形API做抽象
	*/
	class RenderSystem {
	public:
	protected:
		explicit RenderSystem(config::RenderSystem config);
		virtual ~RenderSystem() = default;
		// 禁止拷贝
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem& operator=(const RenderSystem&) = delete;
		// 若派生类支持，允许移动
		RenderSystem(RenderSystem&&) = default;
		RenderSystem& operator=(RenderSystem&&) = default;
	private:
		config::RenderSystem config_;
	};

} // namespace primaldawn
