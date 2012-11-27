#include "../assets.h"

/**
 * Global data structures
 */
void initialize_globals(){
	command_buffer = malloc (sizeof(char)*(MAX_INPUT_LENGTH+1));
	io_buffer = malloc (sizeof(char)*(MAX_IO_LENGTH+1));
	data_buffer_1 = malloc (sizeof(char)*(MAX_INPUT_LENGTH));}
	
void free_globals(){
	free(command_buffer);
	free(io_buffer);
	free(data_buffer_1);}
