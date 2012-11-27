#include <stdio.h>
#include <stdlib.h>
/* This is the maximum number of bytes that can be read from or written to a file with a single file system call using this program.  Since files are limited to 512 bytes length, this should be sufficient. */
/* the format definition is necessary because macro substitutions do not take place within quoted strings */
#define MAX_IO_LENGTH   1024       /* I CHANGED IT FROM 512--->1024 */
#define IO_BUF_FORMAT   "%512s"

/* This is the maximum length of input strings (e.g., file names) read from
the standard input.  This should be large enough for most purposes. */
/* the format definition is necessary because macro substitutions do not take place within quoted strings */
#define MAX_INPUT_LENGTH  512
#define INPUT_BUF_FORMAT  "%1024s"

/**
 * Filesystem Functions
 */

int sfs_open(char *pathname);
int sfs_read(int fd, int start, int length, char *mem_pointer);
int sfs_write(int fd, int start, int length, char *mem_pointer);
int sfs_readdir(int fd, char *mem_pointer);
int sfs_close(int fd);
int sfs_delete(char *pathname);
int sfs_create(char *pathname, int type);
int sfs_getsize(char *pathname);
int sfs_gettype(char *pathname);
int sfs_initialize(int erase);

/**
 * Utility Functions
 */

void initialize_globals();
void free_globals();
int put_bytes(char* s, int bytes);
int get_bytes(char* s, int* bytes);

/**
 * Global data structures
 */

// buffer to hold commands read from standard input
char* command_buffer;
// buffer to hold data going to/from the disk
char* io_buffer;
// the following is used to hold string input parameters, such as file names
char* data_buffer_1;
// the following are used to hold integer input parameters
int p1,p2,p3;
