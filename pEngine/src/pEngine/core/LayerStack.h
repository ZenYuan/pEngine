#pragma once

#include "Core.h"
#include "pepch.h"

namespace pEngine
{
	class Layer;
	class DLL_API LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PopOverLayer(Layer* layer);

		auto begin() { return m_Layers.begin(); }
		auto end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
	};
}