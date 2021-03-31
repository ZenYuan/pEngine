#include <WindowWindows.h>
#include <ApplicationEvent.h>
#include <KeyEvent.h>

namespace pEngine
{

	static uint8_t s_GLFWWindowCount = 0;

	WindowWindows::WindowWindows(WindowProp& winprop)
	{
		Init(winprop);
	}

	WindowWindows::~WindowWindows()
	{
		ShutDown();
	}

	void WindowWindows::Init(WindowProp& winprop)
	{
		m_WinData.m_WinProp.m_Title = winprop.m_Title;
		m_WinData.m_WinProp.m_Width = winprop.m_Width;
		m_WinData.m_WinProp.m_Height = winprop.m_Height;
		
		PE_CORE_INFO("create window Title:{0}, Width:{1}, Height:{2}", winprop.m_Title, winprop.m_Width, winprop.m_Height);
		//init glfwWindow

		if (0 == s_GLFWWindowCount)
		{
			int ret = glfwInit();
			PE_ASSERT(ret, "init GLFW is failed!");
		}
		
		m_Window = glfwCreateWindow((int)winprop.m_Width, (int)winprop.m_Height, winprop.m_Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			PE_ERROR("glfwWindow handle {0} get failed!", s_GLFWWindowCount);
		}
		++s_GLFWWindowCount;

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WinData);
		//开启v-Sync，防止fps彪高
		glfwSwapInterval(1);

		//注册事件
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height )
		{
			WindowData* WinData = (WindowData*)glfwGetWindowUserPointer(window);
			WinData->m_WinProp.m_Width = width;
			WinData->m_WinProp.m_Height = height;

			//调用事件回调函数
			WindowResizeEvent event(width, height);
			WinData->m_Func(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow * window) 
		{
			WindowData* WinData = (WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			WinData->m_Func(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
		{
			WindowData* WinData = (WindowData*)glfwGetWindowUserPointer(window);
			PE_CORE_INFO("key:{0}, scancode:{1}, action:{2}", key, scanCode, action);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(static_cast<KeyCode>(key), action);
					WinData->m_Func(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(static_cast<KeyCode>(key));
					WinData->m_Func(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(static_cast<KeyCode>(key), action);
					WinData->m_Func(event);
					break;
				}
				default:
					break;
			}
		});
	}

	void WindowWindows::ShutDown()
	{
		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;
		if (0 == s_GLFWWindowCount)
		{
			glfwTerminate();
			PE_WARN("no windows exist, release glfw resourse!");
		}
		PE_INFO("current exist windows number is {0}", s_GLFWWindowCount);
	}

	void WindowWindows::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

}