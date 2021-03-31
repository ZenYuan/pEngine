#pragma once

#include "Core.h"
#include "pepch.h"

namespace pEngine
{
	class Event;

	struct WindowProp
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		WindowProp(std::string Title = "pEngine", unsigned int Width = 1280, unsigned int Height = 720) :
			m_Title(Title), m_Width(Width), m_Height(Height) {}
	};

	class DLL_API Window
	{
	public:
		using EventCallBackFunc = std::function<void(Event&)>;

		virtual ~Window() = default;
		virtual void OnUpdate() = 0;     //事件阻塞执行，相当于每帧调用；
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void setEventCallBackFunc(const EventCallBackFunc func) = 0;
	};

	std::unique_ptr<Window> Create(WindowProp&);
}