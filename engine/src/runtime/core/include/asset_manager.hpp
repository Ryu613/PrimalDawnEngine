/*
    资产管理器，负责各种资源的操作和管理
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