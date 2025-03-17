
#pragma once

//for printf and puts
#include <stdio.h>
//for variable number of arguments
#include <stdarg.h>
//for exit
#include <stdlib.h>
#include <stdbool.h>

#ifdef ASSERT
#	undef ASSERT
#endif

#if defined(GLOBAL_DEBUG)
#	define ASSERT(boolean, ...)\
	do\
	{\
		if(!(boolean))\
		{\
			printf("Assertion Failed: ");\
			printf(__VA_ARGS__);\
			exit(0);\
		}\
	} while(0)
#else
#	define ASSERT(boolean, ...)
#endif

#	define LOG_MSG(...)\
	{\
		printf("[Log]: ");\
		printf(__VA_ARGS__);\
	}
#	define LOG_ERR(...)\
	{\
		printf("[Error]: ");\
		printf(__VA_ARGS__);\
	}
#	define LOG_FETAL_ERR(...)\
	{\
		printf("[Fetal Error]: ");\
		printf(__VA_ARGS__);\
		exit(0);\
	}
