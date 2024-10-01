#pragma once

#include "./BaseCamera.h"
#include "Core.h"

namespace BaruahEngine
{
    class BARUAH_API OrthographicCamera : public BaseCamera
    {
    public:
        float left;
        float right;
        float bottom;
        float top;
        float nearPlane;
        float farPlane;

    public:
        OrthographicCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
                       float left, float right, float bottom, float top, float near, float far);

        glm::mat4 getProjectionMatrix() const override;
    };
}
