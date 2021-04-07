#pragma once

#include "Core.h"
#include "pepch.h"

#include "LayerStack.h"

namespace pEngine{

	class Event;
	class Window;
	class WindowResizeEvent;
	class WindowCloseEvent;
	class Layer;

	class DLL_API Application {
	public:
		Application(const std::string& name = "pEngine APP");
		~Application();
		//window»Øµ÷º¯Êý
		void OnEvent(Event& e);
		void Run();
		bool GetRunStatus() const{ return m_Runing; }
		void PushOverLayer(Layer* layer);
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);	
	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Runing;
	};

	Application* CreateApplication();

}
