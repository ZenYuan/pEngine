#pragma once

#include "Core.h"
namespace pEngine
{
	enum class EventType
	{
		None = 0,
		//window
		WindowClose,
		WindowResize,
		WindowFouces,
		WindowLostFocus,
		WindowMoved,
		//App
		AppTock,
		AppUpdate,
		AppRender,
		//key
		KeyPressed,
		KeyReleased,
		KeyTyped,
		//mouse
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

#define EVENT_CLASS_TYEP(type) \
	static EventType GetStaticType() { return EventType::type; } \
	virtual EventType GetEventType() const override { return GetStaticType(); } \
	virtual const char* GetName() const override { return #type; };

	class DLL_API Event
	{
	public:
		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
	public:
		bool m_Handle = false;
	};

	class DLL_API EventDispatcher
	{
	public:
		EventDispatcher(Event& e):m_event(e){}

		//不同的事件类型对应不同的事件处理函数
		template<typename T, typename U>
		void dispatcher(const U& func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_Handle |= func(m_event);
				return;
			}
			return;
		}

	private:
		Event& m_event;
	};

}