
#include <disk_manager/file_writer.h>
//for u64
#include <disk_manager/defines.h>
//for LOG_FETAL_ERR
#include <disk_manager/assert.h>
//for fopen, fclose, putc, and fwrite
#include <stdio.h>

DISK_MANAGER_API void write_text_to_file(const char* file_name, const char* text)
{
	if(text == NULL)
	{
		LOG_FETAL_ERR("Nothing to write to file \"%s\", text data is NULL\n", file_name);
	}
	FILE* file = fopen(file_name, "w");
	if(file == NULL)
	{
		LOG_FETAL_ERR("Opening file \"%s\" failed\n", file_name);
	}
	while(*text != 0)
	{
		putc(*text, file);
		++text;
	}
	fclose(file);
}


DISK_MANAGER_API void write_binary_to_file(const char* file_name, const char* data, u64 length)
{
	if(data == NULL)
	{
		LOG_FETAL_ERR("Nothing to write to file \"%s\", data is NULL\n", file_name);
	}
	FILE* file = fopen(file_name, "wb");
	if(file == NULL)
	{
		LOG_FETAL_ERR("Opening file \"%s\" failed\n", file_name);
	}
	u64 bytes_written = fwrite(data, sizeof(char), length, file);
	if(bytes_written != length)
	{
		LOG_FETAL_ERR("Writing to file \"%s\" failed\n", file_name);
	}
	fclose(file);
}
