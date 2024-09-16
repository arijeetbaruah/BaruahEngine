#include "bepch.h"
#include "PerspectiveCamera.h"

namespace BaruahEngine {
	PerspectiveCamera::PerspectiveCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
		float fov, float aspect, float near, float far) : Camera(startPos, startUp, startYaw, startPitch),
		m_fov(fov), m_aspectRatio(aspect), m_nearPlane(near), m_farPlane(far)
	{
	}

	glm::mat4 PerspectiveCamera::getProjectionMatrix() const
	{
		return glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearPlane, m_farPlane);
	}
}
