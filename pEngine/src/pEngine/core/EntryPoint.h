#pragma once

#ifdef PLATEFORM_WINDOWS

extern pEngine::Application* pEngine::CreateApplication();

int main() {

	pEngine::log::Init();
	PE_CORE_WARN("Init log");
	//创建Application同时将需要关注的事件添加进来layerStack中
	//layerStack由Application回调的事件遍历
	auto app = pEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif