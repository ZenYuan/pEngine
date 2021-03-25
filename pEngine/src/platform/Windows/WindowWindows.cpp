#include <WindowWindows.h>

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
		//¿ªÆôv-Sync£¬·ÀÖ¹fps±ë¸ß
		glfwSwapInterval(1);


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