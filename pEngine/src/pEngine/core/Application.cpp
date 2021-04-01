#include "Application.h"
//event register header --> window.h
#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include <Window.h>
#include <GLFW/glfw3.h>

namespace pEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

#if 1

	bool KeyPressedA(KeyPressedEvent& e)
	{
		PE_INFO(e.GetKeyCode());
		if (KeyCode::Escape == e.GetKeyCode())
		{
			PE_CORE_INFO("window close process!");
		}
		return true;
	}

	bool MPressed(MouseButtonPressedEvent& e)
	{
		PE_INFO("press event: code:{0}", e.GetMouseCode());
		return true;
	}

	bool MReleased(MouseButtonReleasedEvent& e)
	{
		PE_INFO("release event: code:{0}", e.GetMouseCode());
		return true;
	}

	bool MScroll(MouseScrolledEvent& e)
	{
		PE_INFO("scroll event: x:{0}, y:{1}", e.GetxOffset(), e.GetyOffset());
		return true;
	}

	bool MMove(MouseMoveEvent& e)
	{
		PE_INFO("move event: x:{0}, y:{1}",e.GetX(), e.GetY());
		return true;
	}

#endif
	void Application::OnEvent(Event& e)
	{
		//执行window上的必要的函数
		EventDispatcher event(e);
		event.dispatcher<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
		event.dispatcher<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		event.dispatcher<MouseButtonPressedEvent>(MPressed);
		event.dispatcher<MouseButtonReleasedEvent>(MReleased);
		event.dispatcher<MouseMoveEvent>(MMove);
		event.dispatcher<MouseScrolledEvent>(MScroll);
		//将事件分发layer层
	}

	Application::Application(const std::string& name) 
	{
		//create window
		m_Window = Create(WindowProp(name));
		//set callback
		m_Window->setEventCallBackFunc(BIND_EVENT_FN(OnEvent));
		m_Runing = true;
	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		while (m_Runing) 
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			//update window
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		PE_CORE_INFO("current window size: width:{0}, height:{1}", e.GetWidth(), e.GetHeight());
		return true;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Runing = false;
		PE_CORE_WARN("window close!");
		return true;
	}
}