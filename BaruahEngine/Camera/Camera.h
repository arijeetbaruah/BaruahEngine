#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"

namespace BaruahEngine {
	class Camera
	{
	public:
		Camera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch);

		/// <summary>
		/// Pure virtual methods for projection matrices
		/// </summary>
		/// <returns>Matrix 4</returns>
		virtual glm::mat4 getProjectionMatrix() const = 0;

		/// <summary>
		/// Common view matrix
		/// </summary>
		/// <returns>Matrix 4</returns>
		glm::mat4 getViewMatrix() const {
			return glm::lookAt(m_transform.position, m_transform.position + m_front, m_up);
		}

		inline Transform getTransform() const {
			return m_transform;
		}

		inline glm::vec3 getFront() const {
			return m_front;
		}

		inline void setFront(glm::vec3 front)
		{
			m_front = front;
		}

		inline glm::vec3 getUp() const {
			return m_up;
		}

		inline void setUp(glm::vec3 up)
		{
			m_up = up;
		}

		inline glm::vec3 getRight() const {
			return m_right;
		}

		inline void setRight(glm::vec3 right)
		{
			m_right = right;
		}

		inline glm::vec3 getWorldUp() const {
			return m_worldUp;
		}

		inline void setWorldUp(glm::vec3 worldUp)
		{
			m_worldUp = worldUp;
		}

	protected:
		/// <summary>
		/// Update the camera vectors based on the latest yaw and pitch (stored in transform.rotation)
		/// </summary>
		void updateCameraVectors();

	protected:
		Transform m_transform;

		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;
	};
}
