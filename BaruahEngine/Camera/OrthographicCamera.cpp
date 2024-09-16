#include "bepch.h"
#include "OrthographicCamera.h"

namespace BaruahEngine {
	OrthographicCamera::OrthographicCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
		float left, float right, float bottom, float top, float near, float far) : Camera(startPos, startUp, startYaw, startPitch),
		m_left(left), m_right(right), m_bottom(bottom), m_top(top), m_nearPlane(near), m_farPlane(far)
	{
	}

	glm::mat4 OrthographicCamera::getProjectionMatrix() const
	{
		return glm::ortho(m_left, m_right, m_bottom, m_top, m_nearPlane, m_farPlane);
	}
}
