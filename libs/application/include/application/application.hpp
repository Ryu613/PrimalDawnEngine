#pragma once

#include <memory>
#include <string>

#include "primaldawn/config.hpp"

namespace primaldawn {
	class Engine;

	struct ApplicationConfig {
		std::string app_name{ "default" };
		config::Engine engine_config;
	};

	class Application {
	public:
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
		Engine* engine_{ nullptr };
		bool close_ = true;
	};
} // namespace primaldawn
