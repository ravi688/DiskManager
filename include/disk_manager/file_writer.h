
#pragma once

//for stack trace
#include <calltrace/calltrace.h>
//for u64 and DISK_MANAGER_API
#include <disk_manager/defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/* write_text_to_file(const char* file_name, const char* text):
 * PARAMS:
 * 		1. file_name: file path to open
 * 		2. text: pointer to the null terminated text data
 * RETURNS:
 * 		Nothing
 * ERROR DESCRIPTIONS:
 *		1. Nothing to write to file "file_name", text data is NULL , if paramter data is NULL
 * 		2. Opening file "file_name" failed, if failed to open the file with path "file_name"
 * MEMORY OPERATION DESCRIPTIONS:
 * 		1. It doesn't allocate any heap memory
 * NOTE:
 * 		1. parameter text must point to null terminated string data, otherwise internal while loop will run indefinetly resulting in stackoverflow
 *		2. It is guranteed that the written text data would be null terminated.
 *		3. paramter text must point to a valid text data (not binary), though it is not mandatory.
 * EXAMPLES:
 * 		const char* string = "Hello World";
 *		write_text_to_file("myFolder/file.txt", string);
 */
DISK_MANAGER_API function_signature(void, write_text_to_file, const char* file_name, const char* text);
#define write_text_to_file(...) define_alias_function_macro(write_text_to_file, __VA_ARGS__)

/* write_binary_to_file(const char* file_name, const char* data, u64 length)
 * PARAMS:
 *		1. file_name: file path to open
 * 		2. data: pointer to the binary data
 * 		3. length: length of the above binary data
 * RETURNS:
 * 		Nothing
 * ERROR DESCRIPTIONS:
 *		1. Nothing to write to file "file_name", text data is NULL, if parameter data is NULL
 * 		2. Opening file "file_name" failed, if failed to open the file with path "file_name"
 *		3. Writing to file "file_name" failed, if the written data is not equals to the length parameter
 * NOTE: 
 * 		1. parameter should point to a binary data (not text), though it is not mandatory
 *		2. parameter length should be a valid length, take care of overflow!
 * EXAMPLES:
 * 		int data[100]; memset(data, 0, sizeof(int) * 100);
 * 		write_binary_to_file("myFolder/binaryFile.bin", data, sizeof(int) * 100);
 */
DISK_MANAGER_API function_signature(void, write_binary_to_file, const char* file_name, const char* data, u64 length); 
#define write_binary_to_file(...) define_alias_function_macro(write_binary_to_file, __VA_ARGS__)


#ifdef __cplusplus
}
#endif
