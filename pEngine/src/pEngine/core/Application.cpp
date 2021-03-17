#include "Application.h"
#include "ApplicationEvent.h"
#include "Log.h"


namespace pEngine {

	typedef bool(*func)(Event& e);

	bool windowResize(Event& e)
	{
		PE_INFO(e.GetName());
		return true;
	}

	Application::Application() 
	{
		//create window
		//set callback
	}
	Application::~Application() 
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher event(e);
		event.dispatcher<WindowResizeEvent>(windowResize);
	}
	

	void Application::Run() 
	{
		//assume tigger window´°¿ÚÊÂ¼þ
		WindowResizeEvent e(1280, 720);
		OnEvent(e);

		while (true) 
		{
			//update window
		}
	}
}