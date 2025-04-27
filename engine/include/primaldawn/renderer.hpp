#pragma once

#include "primaldawn/api.hpp"

namespace primaldawn {
	class View;
	/**
	* @brief renderer is used for drawing on per-frame image, specifies render config and get frame infos
	*/
	class Renderer : public Api {
	public:
		Engine* GetEngine() noexcept;
		/**
		* @brief render a image (per frame) according to view 
		*/
		void Render(const View* view);
	protected:
		~Renderer() = default;
	};
} // namespace primaldawn
