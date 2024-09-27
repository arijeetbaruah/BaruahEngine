#include "bepch.h"
#include "BaseCamera.h"

namespace BaruahEngine
{
    BaseCamera::BaseCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch)
        : front(glm::vec3(0.0f, 0.0f, -1.0f)), worldUp(startUp)
    {
        transform.position = startPos;
        transform.rotation = glm::vec3(startYaw, startPitch, 0.0f);
        updateCameraVectors();
    }

    void BaseCamera::processMouseMovement(float xoffset, float yoffset)
    {
        float sensitivity = 0.1f;
        transform.rotation.x += xoffset * sensitivity;  // Yaw
        transform.rotation.y += yoffset * sensitivity;  // Pitch

        if (transform.rotation.y > 89.0f) transform.rotation.y = 89.0f;
        if (transform.rotation.y < -89.0f) transform.rotation.y = -89.0f;

        updateCameraVectors();
    }

    void BaseCamera::updateCameraVectors()
    {
        glm::vec3 newFront;
        newFront.x = cos(glm::radians(transform.rotation.x)) * cos(glm::radians(transform.rotation.y));
        newFront.y = sin(glm::radians(transform.rotation.y));
        newFront.z = sin(glm::radians(transform.rotation.x)) * cos(glm::radians(transform.rotation.y));
        front = glm::normalize(newFront);

        right = glm::normalize(glm::cross(front, worldUp));
        up = glm::normalize(glm::cross(right, front));
    }
}
