#pragma once

#include "impl/window_system.hpp"

#include "SDL.h"

#include "primaldawn/config.hpp"

namespace primaldawn {
	class WindowSystemSdl2 : public PdWindowSystem {
	public:
		explicit WindowSystemSdl2(const config::WindowSystem& cfg);

		~WindowSystemSdl2();

		bool ShouldClose() override;

		void DoEvents() override;

		void Close() override;

		void* GetNativeWindow() const override;

	private:
		SDL_Window* sdl_window_{ nullptr };
	};
}
