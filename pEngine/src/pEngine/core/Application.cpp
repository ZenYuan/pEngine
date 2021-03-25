#include "Application.h"
//event register header --> window.h
#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include <Window.h>
#include <GLFW/glfw3.h>

namespace pEngine {

#if 1
	typedef bool(*func)(Event& e);

	bool KeyPressedA(KeyPressedEvent& e)
	{
		PE_INFO(e.GetRepeatCount());
		return true;
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher event(e);
		event.dispatcher<KeyPressedEvent>(KeyPressedA);
	}
#endif

	Application::Application(const std::string& name) 
	{
		//create window
		m_Window = Create(WindowProp(name));
		//set callback
		//m_Window->setEventCallBackFunc(OnEvent);
	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		while (true) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			//update window
			m_Window->OnUpdate();
		}
	}
}