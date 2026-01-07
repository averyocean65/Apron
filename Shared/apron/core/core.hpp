#pragma once

#ifdef _WIN32
	#ifdef _BUILD_APRON_SHARED
		#define APRON_API __declspec(dllexport)
	#else
		#define APRON_API __declspec(dllimport)
	#endif // _BUILD_APRON_SHARED
#endif // _WIN32

// Values for functions that return an integer
#define APRON_SUCCESS 0x01
#define APRON_FAILURE 0x02