
#pragma once

#include <calltrace/calltrace.h>
#include <disk_manager/defines.h>

function_signature(void, write_text_to_file, const char* file_name, const char* text);
#define write_text_to_file(...) define_alias_function_macro(write_text_to_file, __VA_ARGS__)

function_signature(void, write_binary_to_file, const char* file_name, const char* data, u64 length); 
#define write_binary_to_file(...) define_alias_function_macro(write_binary_to_file, __VA_ARGS__)
