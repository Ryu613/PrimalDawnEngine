/*
    ����ģ���࣬�κ���Ҫ����ʵ�ֵ�����Լ̳д���
*/
#pragma once

namespace PrimalDawn {
    template<typename T> class Singleton {
    private:
        // ��ֹ���ƹ�����
        Singleton(const Singleton<T>&);
        // ��ֹ��ֵ������
        Singleton& operator=(const Singleton<T>&);
    protected:
        static T* msSingleton;
    public:
// ���ñ������麯����鵼�µı���
// static_cast����������Ĺ�������ִ��ʱ��thisָ����ܻ����ڹ�����̫����û�û��ָ����������ǻ���ʱ���±���
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