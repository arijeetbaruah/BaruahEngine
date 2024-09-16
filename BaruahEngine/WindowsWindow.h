#pragma once

#include "Core.h"
#include "Window.h"
#include "Entity.h"

struct GLFWwindow;

namespace BaruahEngine {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowData data);
		~WindowsWindow();

		void OnUpdate() override;
		void* GetNativeWindow() override;

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_EventData.EventCallback = callback; }

	private:
		void SetWindowCloseCallback();

	private:
		GLFWwindow* m_Window;
		std::shared_ptr<Entity> m_entity;

		struct WindowEventData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		WindowEventData m_EventData;
	};
}

