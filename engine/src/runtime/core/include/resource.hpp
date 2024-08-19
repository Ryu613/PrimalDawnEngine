#pragma once

#include <string>

namespace PrimalDawn {
    class Resource {
    public:
        virtual ~Resource();
        // ��ȡ��Դ
        virtual void load();
        // ж����Դ
        virtual void unload();
        // ��ȡ��Դ��С
        size_t getSize() const {
            return mSize;
        }

        const std::string& getName() const {
            return mName;
        }
    protected:
        // ��Դ����
        std::string mName;
        // ��Դ��С
        size_t mSize;
    protected:
        // �����࣬����Ĭ�Ϲ�����
        Resource() 
          : mSize(0)
        {}
        // �Ѹ�ֵ����Ҳ����
        Resource& operator=(const Resource& rhs);
    };
}