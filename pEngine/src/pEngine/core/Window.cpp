#include "Window.h"
#include "WindowWindows.h"

namespace pEngine
{
	std::unique_ptr<Window> Create(WindowProp& winProp = WindowProp())
	{
#ifdef PLATEFORM_WINDOWS
		return std::make_unique<WindowWindows>(winProp);
#else   //����ƽ̨���ڴ���
		PE_CORE_ASSERT(false, "not support other platform!");
		return nullptr;
#endif
	}
}