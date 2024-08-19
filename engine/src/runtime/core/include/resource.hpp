#pragma once

#include <string>

namespace PrimalDawn {
    class Resource {
    public:
        virtual ~Resource();
        // 读取资源
        virtual void load();
        // 卸载资源
        virtual void unload();
        // 获取资源大小
        size_t getSize() const {
            return mSize;
        }

        const std::string& getName() const {
            return mName;
        }
    protected:
        // 资源名称
        std::string mName;
        // 资源大小
        size_t mSize;
    protected:
        // 抽象类，避免默认构造器
        Resource() 
          : mSize(0)
        {}
        // 把赋值操作也避免
        Resource& operator=(const Resource& rhs);
    };
}