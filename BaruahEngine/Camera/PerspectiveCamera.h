#pragma once

#include "./BaseCamera.h"
#include "Core.h"

namespace BaruahEngine
{
    class BARUAH_API PerspectiveCamera : public BaseCamera
    {
    public:
        float fov;
        float aspectRatio;
        float nearPlane;
        float farPlane;

    public:
        PerspectiveCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
                      float fov, float aspect, float near, float far);

        glm::mat4 getProjectionMatrix() const override;
    };
}
