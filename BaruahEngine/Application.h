#pragma once
#include "Core.h"

namespace BaruahEngine {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
