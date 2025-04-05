#pragma once

#include "platform/window_system_config.hpp"

namespace primaldawn {
	/**
	* 窗口系统（WSI）总抽象
	*/
	class WindowSystem {
	public:
		inline WindowSystemConfig GetConfig() const {
			return window_system_config_;
		}
	protected:
		explicit WindowSystem(WindowSystemConfig config);
		virtual ~WindowSystem() = default;

		// 只允许移动不允许拷贝
		WindowSystem(const WindowSystem&) = delete;
		WindowSystem& operator=(const WindowSystem&) = delete;
		WindowSystem(WindowSystem&&) = default;
		WindowSystem& operator=(WindowSystem&&) = default;
	private:
		WindowSystemConfig window_system_config_;
	};

} // namespace primaldawn
