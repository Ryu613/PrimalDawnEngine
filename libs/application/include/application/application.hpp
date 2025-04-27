#pragma once

#include <memory>
#include <string>

#include "primaldawn/engine.hpp"

namespace primaldawn {

	struct ApplicationConfig {
		std::string app_name{ "default" };
		bool enable_debug = true;
		size_t window_height = 768;
		size_t window_width = 1024;
		bool window_headless = false;
		bool window_resizable = true;
		mutable WindowSystemType window_api = WindowSystemType::DEFAULT;
		mutable RenderSystemType backend = RenderSystemType::DEFAULT;
		//config::Engine engine_config;
	};

	class Application {
	public:
		static Application& Get();
		~Application();
		Application& Configure(const ApplicationConfig* config = nullptr);
		void Run();
		void Close();
	private:
		Application();

		ApplicationConfig config_;
		Engine* engine_ = nullptr;
		Scene* scene_ = nullptr;
		View* view_ = nullptr;
		Camera* camera_ = nullptr;
		bool close_ = true;
		bool configured_ = false;
	public:
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) noexcept = delete;
		Application& operator=(Application&&) noexcept = delete;
	};
} // namespace primaldawn
