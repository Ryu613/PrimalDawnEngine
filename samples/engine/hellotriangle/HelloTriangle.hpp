#pragma once

#include "application/Application.hpp"

/**
* @brief vulkan最简样例，旨在确认项目是否能正常运行
*/
namespace primaldawn {
	class HelloTriangle : public Application {
		struct AppContext {

		};
	public:
		HelloTriangle(ApplicationConfig config);
		~HelloTriangle();
		void Prepare() override;
		void SetupScene() override;
		void Run() override;
		void Close() override;

	private:

		void initWindow();
		void initRenderSystem();

		AppContext context;
	};
} // namespace primaldawn

