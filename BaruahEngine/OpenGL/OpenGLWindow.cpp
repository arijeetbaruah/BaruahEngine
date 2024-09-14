#include "bepch.h"
#include "./OpenGLWindow.h"
#include <Log.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace BaruahEngine {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowData& datum)
	{
		return new OpenGLWindow(datum);
	}

	OpenGLWindow::OpenGLWindow(WindowData windowDatum) : Window(windowDatum), m_window(0)
	{
		if (!glfwInit())
		{
			BE_CORE_ERROR("Unable to Initialize GLFW!!");
			return;
		}

		m_window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);

		BE_CORE_ASSERT(m_window, "Unable to create Window");

		/* Make the window's context current */
		glfwMakeContextCurrent(m_window);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		glfwTerminate();
	}

	void OpenGLWindow::OnUpdate()
	{
	}
}
