#include "blockio.h"
#include "../assets.h"

typedef struct{
	int index;//index of file's first block on disk
	int size;//size in blocks
	char* name;//name of file
} inode;

char* write_inode(inode i);
inode read_inode(char* s);
char* write_itable(inode* t);
inode* read_itable(char* s);
