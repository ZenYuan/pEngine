#pragma once

#include <Event.h>
#include "KeyCodes.h"

namespace pEngine
{
	class DLL_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y) :
			m_x(x), m_y(y) {}
		inline int GetX() const { return m_x; }
		inline int GetY() const { return m_y; }

		EVENT_CLASS_TYEP(MouseMoved);
	private:
		float m_x;
		float m_y;
	};

	class DLL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset):
			m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetxOffset() const { return m_xOffset; }
		inline float GetyOffset() const { return m_yOffset; }

		EVENT_CLASS_TYEP(MouseScrolled);
	private:
		float m_xOffset;
		float m_yOffset;
	};

	class DLL_API MouseButtonEvnet : public Event
	{
	public:
		MouseButtonEvnet(MouseCode mousecode):
			m_MouseCode(mousecode) {}

		inline MouseCode GetMouseCode() const { return m_MouseCode; }
	private:
		 MouseCode m_MouseCode;
	};

	class DLL_API MouseButtonPressedEvent : public MouseButtonEvnet
	{
	public:
		MouseButtonPressedEvent(MouseCode mousecode):
			MouseButtonEvnet(mousecode) {}

		EVENT_CLASS_TYEP(MouseButtonPressed);
	};

	class DLL_API MouseButtonReleasedEvent : public MouseButtonEvnet
	{
	public:
		MouseButtonReleasedEvent(MouseCode mousecode) :
			MouseButtonEvnet(mousecode) {}

		EVENT_CLASS_TYEP(MouseButtonReleased);
	};
		

}