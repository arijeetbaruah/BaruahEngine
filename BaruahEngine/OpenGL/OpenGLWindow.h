#pragma once
#include "../Window.h"

#include <GLFW/glfw3.h>

namespace BaruahEngine {
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(WindowData windowDatum);
		~OpenGLWindow();

		void OnUpdate() override;

		virtual void* GetNativeWindow() override {
			return m_window;
		}

	private:
		GLFWwindow* m_window;
	};
}

