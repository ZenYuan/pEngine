#pragma once

#ifdef PLATEFORM_WINDOWS

extern pEngine::Application* pEngine::CreateApplication();

int main() {

	pEngine::log::Init();
	PE_CORE_WARN("Init log");
	//����Applicationͬʱ����Ҫ��ע���¼���ӽ���layerStack��
	//layerStack��Application�ص����¼�����
	auto app = pEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif