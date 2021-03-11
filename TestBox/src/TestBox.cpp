#include "pEngine.h"

class Sandbox : public pEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

pEngine::Application* pEngine::CreateApplication()
{
	return new Sandbox();
}