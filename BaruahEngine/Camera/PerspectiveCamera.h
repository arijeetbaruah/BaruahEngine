#pragma once

#include "Camera.h"

namespace BaruahEngine {
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
            float fov, float aspect, float near, float far);

        glm::mat4 getProjectionMatrix() const override;

        inline float getFOV() const {
            return m_fov;
        }

        inline void setFOV(float fov) {
            m_fov = fov;
        }

        inline float getAspectRatio() const {
            return m_aspectRatio;
        }

        inline void setAspectRatio(float aspectRatio)
        {
            m_aspectRatio = aspectRatio;
        }

        inline float getNearPlane() const {
            return m_nearPlane;
        }

        inline void setNearPlane(float nearPlane) {
            m_nearPlane = nearPlane;
        }

        inline float getFarPlane() const {
            return m_farPlane;
        }

        inline void setFarPlane(float farPlane) {
            m_farPlane = farPlane;
        }

    protected:
        float m_fov;
        float m_aspectRatio;
        float m_nearPlane;
        float m_farPlane;
    };
}

