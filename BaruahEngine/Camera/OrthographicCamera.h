#pragma once
#include "Camera.h"

namespace BaruahEngine {
	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(glm::vec3 startPos, glm::vec3 startUp, float startYaw, float startPitch,
			float left, float right, float bottom, float top, float near, float far);

		glm::mat4 getProjectionMatrix() const override;

		inline float getLeft() const {
			return m_left;
		}

		inline void setLeft(float left)
		{
			m_left = left;
		}

		inline float getRight() const {
			return m_right;
		}

		inline void setRight(float right) {
			m_right = right;
		}

		inline float getBottom() const {
			return m_bottom;
		}

		inline void setBottom(float bottom) {
			m_bottom = bottom;
		}

		inline float getTop() const {
			return m_top;
		}

		inline void setTop(float top) {
			m_top = top;
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
		float m_left;
		float m_right;
		float m_bottom;
		float m_top;
		float m_nearPlane;
		float m_farPlane;
	};
}
