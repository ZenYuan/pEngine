#pragma once

#ifdef PLATEFORM_WINDOWS
	#ifdef BUILD_DLL
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __declspec(dllimport)
	#endif
#else
#error not define plateform!
#endif


#ifdef PE_ENABLE_ASSERTS
#define PE_ASSERT(x, ...) { \
	if(!x) { \
		PE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
		__debugbreak(); \
	}\
}
#define PE_CORE_ASSERT(x, ...) { \
	if(!x) { \
		PE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
		__debugbreak(); \
	}\
}
#else
#define PE_ASSERT()
#define PE_CORE_ASSERT()
#endif
