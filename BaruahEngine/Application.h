#pragma once
#include "Core.h"
#include "Window.h"

namespace BaruahEngine {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;

		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
