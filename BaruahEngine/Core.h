#pragma once

#ifdef BE_PLATFORM_WINDOW
	#if HZ_DYNAMIC_LINK
		#ifdef BE_BUILD_DLL
			#define BARUAH_API __declspec(dllexport)
		#else
			#define BARUAH_API __declspec(dllimport)
		#endif // BE_BUILD_DLL
	#else
		#define BARUAH_API
	#endif
#else
	#error Baruah Engine is only supported in Windows!
#endif

