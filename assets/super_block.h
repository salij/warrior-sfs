#include "../assets.h"
#include "blockio.h"
#include "inode.h"
#include <string.h>

typedef struct {
	int blockSize;//in bytes
	int blockCount;//number of blocks on disk
	int super_loc;//blocknum of super block
	int openFileTable_loc;//blocknum of open file table
	int freeBlockTable_loc;//blocknum of free block table
	inode root;//root directory's inode
} Superblock;

Superblock super;

int init_superblock();
int put_super_blk();
int get_super_blk();
