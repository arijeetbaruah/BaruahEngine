#pragma once
#include "Core.h"
#include "./Asset.h"

namespace BaruahEngine
{    
    class BARUAH_API AssetManager
    {
    protected:
        std::unordered_map<std::string, std::shared_ptr<Asset>> assets;
    public:
        template <typename T>
        std::shared_ptr<T> loadAsset(const std::string& assetName, const std::string& filePath);

        void unloadAsset(const std::string& assetName);
        void clear();
    };
}
