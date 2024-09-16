#include "bepch.h"
#include "Camera.h"

namespace BaruahEngine {
    Camera::Camera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch) : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_worldUp(startUp) {
        m_transform.position = startPos;
        m_transform.rotation = glm::vec3(startYaw, startPitch, 0.0f);
        updateCameraVectors();
    }

    void Camera::updateCameraVectors()
    {
        glm::vec3 newFront;
        newFront.x = cos(glm::radians(m_transform.rotation.x)) * cos(glm::radians(m_transform.rotation.y));
        newFront.y = sin(glm::radians(m_transform.rotation.y));
        newFront.z = sin(glm::radians(m_transform.rotation.x)) * cos(glm::radians(m_transform.rotation.y));
        m_front = glm::normalize(newFront);

        m_right = glm::normalize(glm::cross(m_front, m_worldUp));
        m_up = glm::normalize(glm::cross(m_right, m_front));
    }
}
