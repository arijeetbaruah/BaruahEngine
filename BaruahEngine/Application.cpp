#include "bepch.h"
#include "Core.h"
#include "Application.h"
#include "Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Event/ApplicationEvent.h>

namespace BaruahEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application(): m_Running(true)
	{
		BE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		Log::Initialize();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BE_BIND(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		BE_CORE_INFO("{0}", e.ToString());
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BE_BIND(Application::OnWindowClose));
	}

	void Application::Run()
	{
		glfwMakeContextCurrent((GLFWwindow*)m_Window->GetNativeWindow());

		while (m_Running)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
