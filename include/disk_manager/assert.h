
#pragma once

#ifdef __cplusplus
#	include <cstdio>
#	include <cstdarg>
#	include <cstdlib>
#	include <cstdbool>
#else
	//for printf and puts
#	include <stdio.h>
	//for variable number of arguments
#	include <stdarg.h>
	//for exit
#	include <stdlib.h>
#	include <stdbool.h>
#endif

//for log_msg, log_err, log_fetal_err and calltrace_string()
#include <calltrace/calltrace.h>

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
			puts(calltrace_string());\
			exit(0);\
		}\
	} while(0)
#else
#	define ASSERT(boolean, ...)
#endif

#if defined(GLOBAL_DEBUG)
#	define LOG_MSG(...) log_msg(__VA_ARGS__)
#	define LOG_ERR(...) log_err(__VA_ARGS__)
#	define LOG_FETAL_ERR(...) log_fetal_err(__VA_ARGS__)
#else
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
#endif