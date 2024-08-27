/*
    单例模板类，任何需要单例实现的类可以继承此类
*/
#pragma once

namespace PrimalDawn {
    template<typename T> class Singleton {
    private:
        // 禁止复制构造器
        Singleton(const Singleton<T>&);
        // 禁止赋值操作符
        Singleton& operator=(const Singleton<T>&);
    protected:
        static T* msSingleton;
    public:
        // 禁用编译器虚函数检查导致的报错
        // static_cast若在派生类的构造器中执行时，this指针可能会由于构造器太早调用还没能指向派生类而是基类时导致报错
#if defined(__has_attribute)
#  if __has_attribute(no_sanitize)
        __attribute__((no_sanitize("vptr")))
#  endif
#endif
            Singleton() {
            msSingleton = static_cast<T*>(this);
        }
        ~Singleton() {
            msSingleton = 0;
        }

        static T& getSingleton() {
            return *msSingleton;
        }

        static T* getSingletonPtr() {
            return msSingleton;
        }

    };
}