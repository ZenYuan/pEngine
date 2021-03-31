#pragma once

#include "Core.h"
#include "pepch.h"

namespace pEngine{

	class Event;
	class Window;
	class WindowResizeEvent;
	class WindowCloseEvent;

	class DLL_API Application {
	public:
		Application(const std::string& name = "pEngine APP");
		//window»Øµ÷º¯Êý
		void OnEvent(Event& e);
		void Run();
		bool GetRunStatus() const{ return m_Runing; }
		~Application();
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);	
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Runing;
	};

	Application* CreateApplication();

}
