
#pragma once

#include <disk_manager/defines.h>
#include <calltrace/calltrace.h>
#include <buffer.h>

function_signature(BUFFER*, load_text_from_file, const char* file_name);
#define load_text_from_file(...) define_alias_function_macro(load_text_from_file, __VA_ARGS__)

function_signature(BUFFER*, load_binary_from_file, const char* file_name); 
#define load_binary_from_file(...) define_alias_function_macro(load_binary_from_file, __VA_ARGS__)

function_signature(BUFFER*, load_text_from_file_exclude_comments, const char* file_name);
#define load_text_from_file_exclude_comments(...) define_alias_function_macro(load_text_from_file_exclude_comments, __VA_ARGS__)