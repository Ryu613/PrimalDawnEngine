#pragma once

#include <memory>
#include <string>

#include "primaldawn/config.hpp"
#include "primaldawn/engine.hpp"

namespace primaldawn {

	struct ApplicationConfig {
		std::string app_name{ "default" };
		config::Engine engine_config;
	};

	class Application {
	public:
		virtual void Prepare() = 0;
		virtual void SetupScene();
		virtual void Run();
		virtual void Close();
	protected:
		Application(const ApplicationConfig& config);
		virtual ~Application();

		const ApplicationConfig& application_config_;
		Engine* engine_{ nullptr };
		bool close_ = true;
	};
} // namespace primaldawn
