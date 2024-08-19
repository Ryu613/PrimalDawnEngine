/*
    �ʲ������������������Դ�Ĳ����͹���
*/
#pragma once

#include <assert.h>
#include "singleton.hpp"

namespace PrimalDawn {
    class AssetManager : public Singleton<AssetManager> {
    public:
        AssetManager();
        virtual ~AssetManager();
        static AssetManager& getSingleton();
        static AssetManager* getSingletonPtr();
    };
}