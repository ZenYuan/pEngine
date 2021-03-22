#include "Application.h"
//event register header --> window.h
#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "pepch.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace pEngine {

#if 1
	typedef bool(*func)(Event& e);

	bool KeyPressedA(KeyPressedEvent& e)
	{
		PE_INFO(e.GetRepeatCount());
		return true;
	}
#endif

	Application::Application() 
	{
		//create window
		//set callback
	}
	Application::~Application() 
	{

	}

#if 1
	void Application::OnEvent(Event& e)
	{
		EventDispatcher event(e);
		event.dispatcher<KeyPressedEvent>(KeyPressedA);
	}
#endif

	void Application::Run() 
	{
#if 0
		//assume trigger window´°¿ÚÊÂ¼þ
		KeyPressedEvent e(static_cast<KeyCode>(65), 20);
		OnEvent(e);
#endif


//window test
#if 1
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
		while (!glfwWindowShouldClose(window))
		{

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
#endif
		while (true) 
		{
			//update window
		}
	}
}