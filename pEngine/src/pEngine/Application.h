#pragma once

#include "Core.h"

namespace pEngine{

	class DLL_API Application {
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();

}
