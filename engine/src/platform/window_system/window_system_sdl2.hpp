#pragma once

#include "impl/window_system.hpp"

#include "primaldawn/config.hpp"

#include "SDL.h"

namespace primaldawn {
	class WindowSystemSdl2 : public PdWindowSystem {
	public:
		explicit WindowSystemSdl2(config::WindowSystem cfg);

		~WindowSystemSdl2();

		bool ShouldClose() override;

		void DoEvents() override;

		void Close() override;
	private:
		SDL_Window* mSDLWindow{ nullptr };
	};
}
