#pragma once

#include "glm/glm.hpp"
#include <glad/glad.h>

namespace BaruahEngine {
    class Entity
    {
    public:
        Entity();

        void render();
        void update();

    protected:
        GLuint VAO, VBO, EBO;
    };
}
