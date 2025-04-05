#pragma once

#include <memory>
#include <string>

#include "primaldawn/config.hpp"

namespace primaldawn {
	class Engine;

	class Application {
	public:
		struct ApplicationConfig {
			std::string app_name{ "default" };
			config::Engine engine_config;
		};
		virtual void Prepare() = 0;
		virtual void SetupScene();
		virtual void SetupWindow();
		virtual void SetupEngine();
		virtual void Run();
		virtual void Close();
	protected:
		Application(ApplicationConfig config);
		virtual ~Application();
	private:
		ApplicationConfig application_config_;
		std::unique_ptr<Engine> engine_{ nullptr };
	};
} // namespace primaldawn
