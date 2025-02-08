#pragma once

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

/*
	Switches:
		(NOTE: Automatically defined by the build system when building shared or static libraries)
		Development Switches:
			DISK_MANAGER_BUILD_STATIC_LIBRARY
			DISK_MANAGER_BUILD_DYNAMIC_LIBRARY
		(NOTE: Need to be defined by a dependent project before including any of this library's headers)
		UserCode Switches:
			DISK_MANAGER_USE_STATIC_LIBRARY
			DISK_MANAGER_USER_DYNAMIC_LIBRARY
*/

#if (defined _WIN32 || defined __CYGWIN__) && defined(__GNUC__)
#	define DISK_MANAGER_IMPORT_API __declspec(dllimport)
#	define DISK_MANAGER_EXPORT_API __declspec(dllexport)
#else
#	define DISK_MANAGER_IMPORT_API __attribute__((visibility("default")))
#	define DISK_MANAGER_EXPORT_API __attribute__((visibility("default")))
#endif

#ifdef DISK_MANAGER_BUILD_STATIC_LIBRARY
#	define DISK_MANAGER_API
#elif defined(DISK_MANAGER_BUILD_DYNAMIC_LIBRARY)
#	define DISK_MANAGER_API DISK_MANAGER_EXPORT_API
#elif defined(DISK_MANAGER_USE_DYNAMIC_LIBRARY)
#	define DISK_MANAGER_API DISK_MANAGER_IMPORT_API
#elif defined(DISK_MANAGER_USE_STATIC_LIBRARY)
#	define DISK_MANAGER_API
#else
#	define DISK_MANAGER_API
#endif


#if !defined(DISK_MANAGER_RELEASE) && !defined(DISK_MANAGER_DEBUG)
#	warning "None of DISK_MANAGER_RELEASE && DISK_MANAGER_DEBUG is defined; using DISK_MANAGER_DEBUG"
#	define DISK_MANAGER_DEBUG
#endif
