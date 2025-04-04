#pragma once

#include <memory>
#include <string>

#include "core/engine.hpp"

namespace primaldawn {

	class Application {
	public:
		struct ApplicationConfig {
			std::string app_name{ "default" };
			EngineConfig engine_config;
		};
		virtual void prepare() = 0;
		virtual void setupScene() {};
		virtual void setupWindow() {};
		virtual void setupEngine() {};
		virtual void run() {};
		virtual void close() {};
	protected:
		Application(ApplicationConfig config)
		  : application_config_(std::move(config)) {
			engine_ = Engine::Create(config.engine_config);
		}
		virtual ~Application() = default;
	private:
		ApplicationConfig application_config_;
		std::unique_ptr<Engine> engine_{ nullptr };
	};
} // namespace primaldawn
