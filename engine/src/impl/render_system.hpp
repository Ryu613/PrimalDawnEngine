#pragma once

#include "primaldawn/config.hpp"

namespace primaldawn {
	class PdPlatform;
	/**
	* 渲染系统主类，对各种图形API做抽象
	*/
	class PdRenderSystem {
	public:
		explicit PdRenderSystem(const PdPlatform& platform, const config::RenderSystem& config);
		virtual ~PdRenderSystem();

		virtual void BindPipeline();
		virtual void Draw();

		const PdPlatform& GetPlatform() const;

	protected:
		const PdPlatform& platform_;
		config::RenderSystem config_;
	public:
		PdRenderSystem(const PdRenderSystem&) = delete;
		PdRenderSystem& operator=(const PdRenderSystem) = delete;
		PdRenderSystem(PdRenderSystem&&) noexcept = delete;
		PdRenderSystem operator=(PdRenderSystem&&) noexcept = delete;
	};

} // namespace primaldawn
