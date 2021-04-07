#pragma once

#include "pEngine.h"

class ExampleLayer : public pEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override { PE_INFO("ExampleLayer OnUpdate!"); }
	//void OnEvent(pEngine::Event& e) override { PE_TRACE("event:{0}", e); }
};