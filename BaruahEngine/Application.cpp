#include "bepch.h"
#include "Application.h"
#include "iostream"

namespace BaruahEngine {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "test";
		while (true)
		{
		}
	}
}
