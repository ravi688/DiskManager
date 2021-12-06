
//for printf, and puts
#include <stdio.h>
//for write_text_to_file
#include <disk_manager/file_reader.h>
//for load_binary_from_file and load_text_from_file
#include <disk_manager/file_writer.h>

int main(int argc, char** argv)
{
	// BUFFER* data = load_text_from_file("makefile");
	// puts(data->bytes);
	// buf_free(data);
	BUFFER* binary_data = load_binary_from_file("fragmentShader.spv");
	printf("Binary length: %u\n", binary_data->element_count);

	BUFFER* another_data = load_text_from_file("DiskManager.gv");
	puts(another_data->bytes);	
	write_text_to_file("AnotherDiskManager.txt", another_data->bytes);
	buf_free(another_data);
	buf_free(binary_data);
	return 0;
}