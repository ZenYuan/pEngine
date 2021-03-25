#pragma once

#include <Window.h>
#include <GLFW/glfw3.h>

namespace pEngine
{

	class WindowWindows : public Window
	{
	public:
		WindowWindows(WindowProp& winprop);
		virtual ~WindowWindows();

		void OnUpdate() override;
		unsigned int GetWidth() const override { return m_WinData.m_WinProp.m_Width; }
		unsigned int GetHeight() const override { return m_WinData.m_WinProp.m_Height; }
		void setEventCallBackFunc(const EventCallBackFunc& func) override { m_WinData.m_Func = func; }

	private:
		virtual void Init(WindowProp&);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			WindowProp m_WinProp;
			Window::EventCallBackFunc m_Func;
		};
		WindowData m_WinData;
	};
}