#include "bepch.h"
#include "PerspectiveCamera.h"

namespace BaruahEngine
{
    PerspectiveCamera::PerspectiveCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
        float fov, float aspect, float near, float far)
        : BaseCamera(startPos, startUp, startYaw, startPitch),
             fov(fov), aspectRatio(aspect), nearPlane(near), farPlane(far)
    {
    }

    glm::mat4 PerspectiveCamera::getProjectionMatrix() const
    {
        return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }
}
