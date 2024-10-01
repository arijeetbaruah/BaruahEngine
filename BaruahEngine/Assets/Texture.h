#pragma once

#include "./Asset.h"

#include <glad/glad.h>

namespace BaruahEngine
{
    class Texture : public Asset
    {
    public:
        GLuint textureID;

    public:
        ~Texture();
        void loadFromFile(const std::string& filePath) override;
    };
}
