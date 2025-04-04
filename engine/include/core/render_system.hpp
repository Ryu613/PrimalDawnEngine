#pragma once

#include "core/render_system_config.hpp"

namespace primaldawn {
	/**
	* 渲染系统主类，对各种图形API做抽象
	*/
	template <class RenderSystemSub>
	class RenderSystem {
	public:
		inline RenderSystemConfig GetConfig() const {
			return render_system_config_;
		}
	protected:
		explicit RenderSystem(RenderSystemConfig config);
		virtual ~RenderSystem() = default;
		// 禁止拷贝
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem& operator=(const RenderSystem&) = delete;
		// 若派生类支持，允许移动
		RenderSystem(RenderSystem&&) = default;
		RenderSystem& operator=(RenderSystem&&) = default;
	private:
		RenderSystemConfig render_system_config_;
	};

} // namespace primaldawn
