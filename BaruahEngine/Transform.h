#pragma once

#include "glm/glm.hpp"

namespace BaruahEngine {
    struct Transform {
        glm::vec3 position;
        glm::vec3 rotation; // We'll store Euler angles (yaw, pitch, roll) for simplicity
        glm::vec3 scale;

        Transform() : position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)),scale(glm::vec3(1.0f, 1.0f, 1.0f))
        {
        }
    };
}
