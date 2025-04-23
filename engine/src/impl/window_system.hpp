#pragma once

#include "primaldawn/config.hpp"

namespace primaldawn {
	/**
	* 窗口系统
	*/
	class PdWindowSystem {
	public:
		explicit PdWindowSystem(const config::WindowSystem& config);
		virtual ~PdWindowSystem();

		/**
	   * @brief 用于检查窗口是否应该被关闭
	   */
		virtual bool ShouldClose() = 0;

		/**
		* @brief 处理窗口事件
		*/
		virtual void DoEvents();

		/**
		* @brief 关闭窗口
		*/
		virtual void Close() = 0;

		virtual void* GetNativeWindow() const = 0;

		const config::WindowSystem& GetConfig() const;

	protected:
		config::WindowSystem config_;
		bool closed_ = true;
	};

} // namespace primaldawn
