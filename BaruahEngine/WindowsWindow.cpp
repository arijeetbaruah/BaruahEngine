#include "bepch.h"
#include "WindowsWindow.h"
#include "Log.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <Event/ApplicationEvent.h>

namespace BaruahEngine {
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int errorCode, const char* message)
	{
		BE_CORE_ERROR("GFLW Error({0}): {1}", errorCode, message);
	}

	WindowsWindow::WindowsWindow(WindowData data) : Window(data)
	{
		BE_CORE_INFO("Creating window {0} ({1}, {2})", data.Title, data.Width, data.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			BE_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)data.Width, (int)data.Height, data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BE_CORE_ASSERT(status, "Failed to Initialize Glad");
		glfwSetWindowUserPointer(m_Window, &m_EventData);
		//SetVSync(true);

		SetWindowCloseCallback();
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void* WindowsWindow::GetNativeWindow()
	{
		return m_Window;
	}

	void WindowsWindow::SetWindowCloseCallback()
	{
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowEventData& data = *(WindowEventData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
		});
	}

	Window* Window::Create(const WindowData& datum)
	{
		return new WindowsWindow(datum);
	}
}
