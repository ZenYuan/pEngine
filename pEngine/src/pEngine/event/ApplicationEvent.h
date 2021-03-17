#pragma once
#include "Event.h"
#include <string>

namespace pEngine
{
	class DLL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYEP(WindowClose);
	};

	class DLL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		EVENT_CLASS_TYEP(WindowResize);
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class DLL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYEP(AppUpdate);

	};
}