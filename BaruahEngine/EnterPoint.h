#pragma once


#ifdef BE_PLATFORM_WINDOW

extern BaruahEngine::Application* BaruahEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = BaruahEngine::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Baruah Engine is only supported in Windows!
#endif