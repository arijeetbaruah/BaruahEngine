#pragma once

#include "glm/glm.hpp"
#include <glad/glad.h>

namespace BaruahEngine {
    class Entity
    {
    public:
        Entity();
        ~Entity();

        void render();
        void update();

    protected:
        GLuint VBO;
        
        GLuint shaderProgram;
        GLuint vertexShader;
        GLuint fragmentShader;
    };
}
