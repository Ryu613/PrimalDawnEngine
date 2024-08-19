#include "asset_manager.hpp"

namespace PrimalDawn {
    template<> AssetManager* Singleton<AssetManager>::msSingleton = 0;
    AssetManager::AssetManager() {
    }

    AssetManager::~AssetManager() {
    }
    AssetManager* AssetManager::getSingletonPtr() {
        return msSingleton;
    }
    AssetManager& AssetManager::getSingleton() {
        assert(msSingleton);
        return (*msSingleton);
    }
}