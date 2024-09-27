#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"

namespace BaruahEngine
{
    class BaseCamera
    {
    public:
        Transform transform;  // Use the Transform structure
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;

    public:
        BaseCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch);
        virtual ~BaseCamera() {}

        // Pure virtual methods for projection matrices
        virtual glm::mat4 getProjectionMatrix() const = 0;

        // Common view matrix
        glm::mat4 getViewMatrix() const {
            return glm::lookAt(transform.position, transform.position + front, up);
        }

        void processKeyboardMovement(glm::vec3 direction, float speed) {
            transform.position += direction * speed;
        }

        void processMouseMovement(float xoffset, float yoffset);

    private:
        // Update the camera vectors based on the latest yaw and pitch (stored in transform.rotation)
        void updateCameraVectors();
    };
};
