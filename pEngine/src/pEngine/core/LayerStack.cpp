#include <LayerStack.h>
#include <Layer.h>

namespace pEngine
{
	LayerStack::~LayerStack()
	{
		for (Layer* Layer : m_Layers)
		{
			delete Layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		if (nullptr != layer)
		{
			m_Layers.emplace(m_Layers.begin(), layer);
		}
	}

	void LayerStack::PushOverLayer(Layer* layer)
	{
		if (nullptr != layer)
		{
			m_Layers.emplace_back(layer);
		}
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}

	void LayerStack::PopOverLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}