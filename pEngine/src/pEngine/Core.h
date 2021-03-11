#pragma once

#ifdef PLATEFORM_WINDOWS
	#ifdef BUILD_DLL
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __declspec(dllimport)
	#endif
#else
#endif
