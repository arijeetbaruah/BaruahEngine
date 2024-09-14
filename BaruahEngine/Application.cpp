#include "bepch.h"
#include "Core.h"
#include "Application.h"
#include "Log.h"

namespace BaruahEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application(): m_Running(true)
	{
		BE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		Log::Initialize();

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
