#pragma once

#ifdef PLATEFORM_WINDOWS

extern pEngine::Application* pEngine::CreateApplication();


int main() {
	
	pEngine::log::Init();
	PE_CORE_WARN("Init log");
	int a = 5;
	//PE_INFO("var={0}", a);
	auto app = pEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif