
#include <disk_manager/file_reader.h>
#include <disk_manager/assert.h>
#include <buffer.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>


function_signature(BUFFER*, load_binary_from_file, const char* file_name)
{
	CALLTRACE_BEGIN();
	FILE* file = fopen(file_name, "rb");
	if(file == NULL)
	{
		LOG_FETAL_ERR("File \"%s\" loading failed\n", file_name);
	}
	BUFFER* memory_buffer = BUFcreate(NULL, sizeof(char), 0, 0);
	fseek(file, 0L, SEEK_END);
	u64 length = ftell(file);
	rewind(file);
	buf_resize(memory_buffer, length);
	u64 read_length = fread(memory_buffer->bytes, sizeof(char), length, file);
	ASSERT(length == read_length, "length != read_length\n");
	buf_set_element_count(memory_buffer, read_length);
	fclose(file);
	buf_fit(memory_buffer);
	CALLTRACE_RETURN(memory_buffer);
}

function_signature(BUFFER*, load_text_from_file, const char* file_name)
{
	CALLTRACE_BEGIN();
	FILE* file = fopen(file_name, "r");
	if(file == NULL)
	{
		LOG_FETAL_ERR("File \"%s\" loading failed\n", file_name);
	}
	BUFFER* memory_buffer = BUFcreate(NULL, sizeof(char), 0, 0);
	while(!feof(file))
	{
		char ch = getc(file);
		buf_push(memory_buffer, &ch);
	}
	fclose(file);
	buf_fit(memory_buffer);
	CALLTRACE_RETURN(memory_buffer);
}

function_signature(BUFFER*, load_text_from_file_exclude_comments, const char* file_name)
{
	CALLTRACE_BEGIN();
	FILE* file = fopen(file_name, "r"); 
	if(file == NULL)
	{
		LOG_FETAL_ERR("File \"%s\" loading failed\n", file_name);
	}

	BUFFER* memory_buffer = BUFcreate(NULL, sizeof(char), 0, 0);
	char ch = getc(file);
	char previous_ch = ch;
	bool single_line_comment_begin = false; 
	bool multiple_line_comment_begin = false;

	while(ch != EOF)
	{
		if(!single_line_comment_begin && !multiple_line_comment_begin)
			buf_push(memory_buffer, &ch);
		previous_ch = ch;  
		ch = getc(file);

		if(multiple_line_comment_begin && (previous_ch == '*') && (ch == '/'))
		{
			multiple_line_comment_begin = false;
			buf_pop(memory_buffer, NULL);
			ch = getc(file); 
			ch = getc(file);
			continue;
		}
		else if(single_line_comment_begin && (ch == '\n'))
		{
			single_line_comment_begin = false; 
			ch = getc(file);
			continue;
		}

		if(!multiple_line_comment_begin && !single_line_comment_begin && (previous_ch == '/') && (ch == '/'))
		{
			single_line_comment_begin = true;
			buf_pop(memory_buffer, NULL);
			ch = getc(file); 
			continue;
		}
		if(!single_line_comment_begin && !multiple_line_comment_begin && (previous_ch == '/') && (ch == '*'))
		{
			multiple_line_comment_begin = true;
			ch = getc(file); 
			continue;
		}
	}
	fclose(file);
	char null_value = 0;
	buf_push(memory_buffer, &null_value); 
	buf_fit(memory_buffer); 
	CALLTRACE_RETURN(memory_buffer);
}