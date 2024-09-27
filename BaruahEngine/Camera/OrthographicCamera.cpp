#include "bepch.h"
#include "OrthographicCamera.h"

namespace BaruahEngine
{
    OrthographicCamera::OrthographicCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
        float left, float right, float bottom, float top, float near, float far)
        : BaseCamera(startPos, startUp, startYaw, startPitch),
              left(left), right(right), bottom(bottom), top(top), nearPlane(near), farPlane(far)
    {
    }

    glm::mat4 OrthographicCamera::getProjectionMatrix() const
    {
        return glm::ortho(left, right, bottom, top, nearPlane, farPlane);
    }
}
