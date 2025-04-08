#pragma once

namespace primaldawn {
	/**
	* @brief 平台层: 操作系统，窗口系统相关功能
	*/
	class Platform {
	protected:
		Platform() = default;
		~Platform() = default;
	public:
		// 不允许移动拷贝
		Platform(const Platform& platform) = delete;
		Platform& operator=(const Platform&) = delete;
		Platform(Platform&&) = delete;
		Platform& operator=(Platform&&) = delete;
	};
} // namespace primaldawn
