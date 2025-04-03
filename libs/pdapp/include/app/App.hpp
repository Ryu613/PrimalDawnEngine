#pragma once

#include<memory>
#include <string>

namespace pd {
	class Engine;
	class WindowSystem;
	class App {
	public:
		struct AppConfig {
			std::string appName{ "default" };
			EngineConfig engineConfig = {};
		};
		virtual void prepare() = 0;
		virtual void setupScene() {};
		virtual void setupWindow() {};
		virtual void setupEngine() {};
		virtual void run() {};
		virtual void close() {};
	protected:
		App(AppConfig& appConfig)
		  : mAppConfig(appConfig) {
			mEngine = Engine::create(appConfig.engineConfig);
		}
	private:
		AppConfig& mAppConfig;
		std::unique_ptr<Engine> mEngine{ nullptr };
		std::unique_ptr<WindowSystem> mWindow{ nullptr };
	};
}
