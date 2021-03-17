#pragma once

#include "Core.h"

namespace pEngine{

	class Event;

	class DLL_API Application {
	public:
		Application();
		~Application();
	public:
		//回调事件
		void OnEvent(Event& e);

		void Run();
	};

	Application* CreateApplication();

}
