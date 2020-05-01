#pragma once

#pragma region Shared Library Building
#if defined (_WIN32)
    #if defined(OBL_ENGINE) && !defined(OBL_BUILD_DLL)
		#define OBL_BUILD_DLL
    #elif !defined(OBL_CONSUME_DLL)
		#define OBL_CONSUME_DLL
	#endif

	#if defined(OBL_BUILD_DLL) && defined(OBL_CONSUME_DLL)
		#error You must not define both OBL_BUILD_DLL and OBL_CONSUME_DLL at the same time!
	#endif
	
	#if defined(OBL_BUILD_DLL)
		#define OBLAPI __declspec(dllexport)
	#elif defined(OBL_CONSUME_DLL)
		#define OBLAPI __declspec(dllimport)
	#else
		#define OBLAPI
	#endif
#else
	#error Obelisk only supports Windows!
#endif
#pragma endregion

#pragma region Macro Argument Overloading
	#define _OBL_EXPAND(x) x
	#define _OBL_CAT(a, b) a##b
	#define _OBL_SELECT(name, num) _OBL_CAT(name##_, num)
	#define _OBL_GET_COUNT(_1, _2, _3, _4, _5, count, ...) count
	#define _OBL_VA_SIZE(...) _OBL_EXPAND(_OBL_GET_COUNT(__VA_ARGS__, 5, 4, 3, 2, 1))
	#define _OBL_VA_SELECT(name, ...) _OBL_EXPAND(_OBL_SELECT(name, _OBL_VA_SIZE(__VA_ARGS__))(__VA_ARGS__))
	#define _OBL_MACRO_OVERLOAD(name, ...) _OBL_EXPAND(_OBL_VA_SELECT(name, __VA_ARGS__))
#pragma endregion

#pragma region Asserts
	#if !defined OBL_RELEASE
		#include <cassert>
		#define OBL_ASSERT(condition) assert(condition)
	#else
		#define OBL_ASSERT(condition)
	#endif
#pragma endregion