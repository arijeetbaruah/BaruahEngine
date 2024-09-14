#pragma once
#include "Core.h"
#include "Event.h"

namespace BaruahEngine {
	using EventCallbackFn = std::function<void(BaruahEngine::Event&)>;

	struct BARUAH_API WindowData
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowData(const std::string& title = "Baruah Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class BARUAH_API Window
	{
	public:
		Window(WindowData data): m_Data(data) {}
		
		virtual void OnUpdate() = 0;

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void* GetNativeWindow() = 0;

		static Window* Create(const WindowData& datum = WindowData());

	protected:
		WindowData m_Data;
	};
}
