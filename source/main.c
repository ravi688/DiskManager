
#include <stdio.h>
#include <disk_manager/file_reader.h>

int main(int argc, char** argv)
{
	BUFFER* data = load_text_from_file("makefile");
	puts(data->bytes);
	buf_free(data);
	return 0;
}