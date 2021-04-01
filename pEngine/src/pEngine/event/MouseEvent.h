#pragma once

#include <Event.h>
#include "KeyCodes.h"

namespace pEngine
{
	class DLL_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(double x, double y) :
			m_x(x), m_y(y) {}
		inline double GetX() const { return m_x; }
		inline double GetY() const { return m_y; }

		EVENT_CLASS_TYEP(MouseMoved);
	private:
		double m_x;
		double m_y;
	};

	class DLL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(double xOffset, double yOffset):
			m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline double GetxOffset() const { return m_xOffset; }
		inline double GetyOffset() const { return m_yOffset; }

		EVENT_CLASS_TYEP(MouseScrolled);
	private:
		double m_xOffset;
		double m_yOffset;
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