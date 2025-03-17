
#pragma once

//For BUFFER* 
#include <bufferlib/buffer.h>

// for DISK_MANAGER_API
#include <disk_manager/defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/* load_text_from_file(const char* file_name):
 * PARAMS: 
 * 		1. file_name: file path to open
 * RETURNS:
 * 		BUFFER* object having element_size = sizeof(char) and element_count = length of the file to open in bytes
 * ERROR DESCRIPTIONS:
 * 		1. File "file_name" loading failed, if failed to open the file (FILE* == NULL)
 * 		2. BUFFER is empty, if the opened file contains nothing
 * MEMORY OPERATION DESCRIPTIONS:
 *      1. It allocates heap memory for the loading the data and returns as a BUFFER* object
 * NOTE:
 * 		1. Only text files should be opened due to its internal implementation -> while !feof(file)
 *		2. It is not guaranteed that the loaded text would be null terminated, but it is guaranteed when the file
 * 			contains null character itself. 
 * EXAMPLES:
 * 		BUFFER* file_data = load_text_from_file("resource/ASCII-box.stl");
 *		puts(file_data->bytes) or puts(buf_get_ptr())
 * 		buf_free(file_data);
 */
DISK_MANAGER_API BUFFER* load_text_from_file(const char* file_name);

DISK_MANAGER_API BUFFER* load_text_from_file_s(const char* file_name);

/* load_binary_from_file(const char* file_name):
 * PARAMS:
 * 		1. file_name: file path to open
 * RETURNS: 
 * 		BUFFER* object having element_size = sizeof(char) and element_count = length of the file to open in bytes
 * MEMORY OPERATION DESCRIPTIONS:
 *      1. It allocates heap memory for the loading the data and returns as a BUFFER* object
 * ERROR DESCRIPTIONS:
 * 		1. File "file_name" loading failed, if failed to open the file (FILE* == NULL)
 * 		2. length != read_length, if failed to read all the bytes
 * 		3. new_capacity == 0, if the opened file contains nothing
 * 		4. BUFFER is empty, if the above error doesn't occur then this would if the opened file contains nothing
 * NOTE:
 * 		1. Only binary files should be opened due to its internal implementation -> fread()
 * EXAMPLES:
 * 		BUFFER* file_data = load_binary_from_file("resource/Binary-box.stl");
 *		stl_parse_binary(file_data->bytes, file_data->element_size, &callbacks);
 *		buf_free(file_data);
 */
DISK_MANAGER_API BUFFER* load_binary_from_file(const char* file_name); 

/* load_text_file_exclude_comments(const char* file_name)
 * PARAMS:
 * 		1. file_name: file path to open
 * RETURNS:
 * 		BUFFER* object having element_size = sizeof(char) and element_count = vary dependending on how much text is commented out
 * ERROR DESCRIPTIONS:
 * 		1. File "file_name" loading failed, if failed to open the file (FILE* == NULL)
 * MEMORY OPERATION DESCRIPTIONS:
 *      1. It allocates heap memory for the loading the data and returns as a BUFFER* object
 * NOTE:
 * 		1. It is guaranteed that the loaded text data would be null terminated.
 * 		2. SHOULD NOT BE USED, because it is not well tested
 */
DISK_MANAGER_API BUFFER* load_text_from_file_exclude_comments(const char* file_name);

#ifdef __cplusplus
}
#endif
