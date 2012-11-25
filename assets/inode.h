#include "blockio.h"
#include "../assets.h"
#include <string.h>

#define index_pos 0
#define size_pos 1
#define type_pos 2
#define length_pos 3
#define name_pos 4 //name must always be last

typedef struct{
	int index;//index of file's first block on disk
	int size;//size in blocks
	int type;//0 if directory, 1 otherwise
	char* name;//name of file
} inode;

char* write_inode(inode i);
inode read_inode(char* s);
char* write_itable(inode* t, int t_size, int size_alloc);
inode* read_itable(char* s);
