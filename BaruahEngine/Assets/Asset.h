#pragma once

namespace BaruahEngine
{
    class Asset
    {
    public:
        virtual ~Asset() = default;
        virtual void loadFromFile(const std::string& filePath) = 0;
    };
}
