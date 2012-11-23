#include "blockio.h"
#include "super_block.h"
#include "../assets.h"

int sfs_initialize(int erase){
	int i= 0;
	if (erase = 1)	{
		char * buf;
		buf = (char *) calloc(128, sizeof(char));
		for(i = 0; i < 512; i++)
			if (put_block(i,buf) == -1)
				return 0;}

	Superblock superblock = { 
		.sbBlockSize = "128",
		.sbNumberOfBlocks = "512",
		.sbRootDirectory = "11"};
	

	if (put_super_blk(superblock) == -1)
		return -1;
	return 1;}
