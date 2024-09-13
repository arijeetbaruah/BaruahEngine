#include "bepch.h"
#include "Core.h"
#include "Application.h"
#include "Log.h"

namespace BaruahEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		Log::Initialize();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		BE_CORE_INFO("Welcome to Baruah Engine!!!");

		while (true)
		{
		}
	}
}
