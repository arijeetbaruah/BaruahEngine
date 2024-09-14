#pragma once
#include "Core.h"
#include "Window.h"
#include "Event/ApplicationEvent.h"

namespace BaruahEngine {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;

		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
