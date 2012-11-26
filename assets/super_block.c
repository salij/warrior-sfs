#include "super_block.h"

int init_superblock(){
	super = {
		.blockSize = 128,
		.blockCount= 512,
		.super_loc= 0,
		.openFileTable_loc= 1,
		.freeBlockTable_loc= 2,
		.root = {
			.index = 3,
			.size = 1,
			.type = 0,
			.name = malloc(4*sizeof(char))}}
	super.root.name = "root";
	return put_super_block;}

int put_super_block(Superblock superblock){
	char* block_buff;
	block_buff = malloc(128 * sizeof(char));
	

int get_super_block() {
	char* block_buff;
	
}
