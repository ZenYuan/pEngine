#pragma once

#include "Core.h"
#include "pepch.h"

namespace pEngine{

	class Event;
	class Window;

	class DLL_API Application {
	public:
		Application(const std::string& name = "pEngine APP");
		~Application();
	public:
		//回调事件
		void OnEvent(Event& e);

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();

}
