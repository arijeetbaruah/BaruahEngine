#include "bepch.h"
#include "./AssetManager.h"

namespace BaruahEngine
{
    template <typename T>
    std::shared_ptr<T> AssetManager::loadAsset(const std::string& assetName, const std::string& filePath) {
        // Check if asset is already loaded
        auto it = assets.find(assetName);
        if (it != assets.end()) {
            return std::dynamic_pointer_cast<T>(it->second);
        }

        // Load a new asset
        std::shared_ptr<T> asset = std::make_shared<T>();
        asset->loadFromFile(filePath);
        assets[assetName] = asset;

        return asset;
    }

    void AssetManager::unloadAsset(const std::string& assetName) {
        assets.erase(assetName);
    }

    void AssetManager::clear() {
        assets.clear();
    }
}
