#include "blockio.h"
#include "super_block.h"
#include "../assets.h"

int put_super_blk(Superblock superblock){
	char * super_blk_buf;
	char * delimiter = "|";
	super_blk_buf = (char *) calloc(128, sizeof(char));
	memcpy(super_blk_buf, superblock.sbBlockSize, sizeof(superblock.sbBlockSize));
	strcat(super_blk_buf, delimiter);
	strcat(super_blk_buf, superblock.sbNumberOfBlocks);
	strcat(super_blk_buf, delimiter);
	strcat(super_blk_buf, superblock.sbRootDirectory);
	if(put_block(0, super_blk_buf) == -1)
		return -1;
	else
		return 1;
}

int get_super_blk() {
	char * super_blk_buf;
	if(get_block(0, super_blk_buf) == -1)
		return -1;
	else
		return 1;
}
