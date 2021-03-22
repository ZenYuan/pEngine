#pragma once

#include "Core.h"
#include "Event.h"
#include "KeyCodes.h"

namespace pEngine
{
	class DLL_API KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return m_keyCode; }
	protected:
		KeyEvent(KeyCode keycode) :
			m_keyCode(keycode) {}

		KeyCode m_keyCode;
	};

	class DLL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode, int repeatCount) :
			KeyEvent(keycode),
			m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_CLASS_TYEP(KeyPressed);
	
	private:
		int m_RepeatCount;
	};

	class DLL_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(KeyCode keycode) :
			KeyEvent(keycode) {}

		EVENT_CLASS_TYEP(KeyReleased);
	};

}