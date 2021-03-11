#pragma once

#ifdef PLATEFORM_WINDOWS

extern pEngine::Application* pEngine::CreateApplication();


int main() {
	auto app = pEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif