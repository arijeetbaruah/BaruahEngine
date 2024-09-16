#include "bepch.h"
#include "WindowsWindow.h"
#include "Log.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <Event/ApplicationEvent.h>
#include "Camera/PerspectiveCamera.h"

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

		m_entity = std::make_shared<Entity>();

		m_camera = std::make_shared<PerspectiveCamera>(glm::vec3(0.0f, 0.0f, 3.0f), // Position
			glm::vec3(0.0f, 1.0f, 0.0f), // Up vector
			-90.0f, 0.0f,                // Yaw and Pitch
			45.0f, 800.0f / 600.0f,      // FOV and Aspect Ratio
			0.1f, 100.0f);               // Near and Far Plane
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		m_entity->update();

		glm::mat4 projectionMatrix = m_camera->getProjectionMatrix();
		glm::mat4 viewMatrix = m_camera->getViewMatrix();

		m_entity->render();

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
