
//#include "ExampleLayer.h"
//place the end
#include "pEngine.h"


class ExampleLayer : public pEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override { PE_INFO("ExampleLayer OnUpdate!"); }
	void OnEvent(pEngine::Event& e) override { PE_INFO("event:{0}", e.GetName()); }
};


class Sandbox : public pEngine::Application
{
public:
	Sandbox()
	{
		PushOverLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

pEngine::Application* pEngine::CreateApplication()
{
	return new Sandbox();
}