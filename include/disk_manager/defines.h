
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


#ifdef DISK_MANAGER_STATIC_LIBRARY
#	define DISK_MANAGER_API
#elif DISK_MANAGER_DYNAMIC_LIBRARY
#	define DISK_MANAGER_API __declspec(dllimport)
#elif BUILD_DYNAMIC_LIBRARY
#	define DISK_MANAGER_API __declspec(dllexport)
#else
#	define DISK_MANAGER_API
#endif
