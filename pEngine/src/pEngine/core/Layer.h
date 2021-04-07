#pragma once

#include "Core.h"
#include "pepch.h"

namespace pEngine
{
	class Event;

	class DLL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") :
			m_DebugName(name) {}
		virtual ~Layer() = default;
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
	private:
		std::string m_DebugName;
	};
}