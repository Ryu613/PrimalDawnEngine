#pragma once

#include "impl/window_system.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "primaldawn/config.hpp"

namespace primaldawn {
	class WindowSystemGlfw3 : public PdWindowSystem {
	public:
		explicit WindowSystemGlfw3(config::WindowSystem cofig);

		~WindowSystemGlfw3();

		bool ShouldClose() override;

		void DoEvents() override;

		void Close() override;
	private:
		GLFWwindow* glfw_window_{ nullptr };
	};

	inline void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

	inline void processInput(GLFWwindow* window);

} // namespace primaldawn
