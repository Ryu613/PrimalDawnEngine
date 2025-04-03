#pragma once

#include <cassert>

namespace pd {
	/**
	* @ brief 单例模板类，保证继承类的实例全局唯一
	*/
	template<typename T> class Singleton {
	private:
		/**
		* brief 不允许拷贝
		*/
		Singleton(const Singleton<T>&);

		/**
		* @brief 不允许赋值
		*/
		Singleton& operator=(const Singleton<T>&);

	protected:
		static T* mSingleton;
	public:
		Singleton() {
			assert(!mSingleton);
			mSingleton = static_cast<T*>(this);
		}
		~Singleton() {
			assert(mSingleton);
			mSingleton = 0;
		}
		static T& getSingleton() {
			assert(mSingleton);
			return (*mSingleton);
		}

		static T* getSingletonPtr() {
			return mSingleton;
		}
	};
}
