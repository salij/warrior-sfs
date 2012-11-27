#include "superblock.h"

int init_superblock(){
	super.blockSize = 128;
	super.blockCount= 512;
	super.super_loc= 0;
	super.openFileTable_loc= 1;
	super.freeBlockTable_loc= 2;
	super.root.index = 3;
	super.root.size = 1;
	super.root.type = 0;
	super.root.name = malloc(4*sizeof(char));
	super.root.name = "root";
	return put_superblock();}

int put_superblock(){
	char* buffer = malloc(128 * sizeof(char));
	int ret;
	//write the integer fields to buffer
	ret = put_bytes( buffer + 0, super.blockSize);
	ret = put_bytes( buffer + 2, super.blockCount);
	ret = put_bytes( buffer + 4, super.super_loc);
	ret = put_bytes( buffer + 6, super.openFileTable_loc);
	ret = put_bytes( buffer + 8, super.freeBlockTable_loc);
	//write the root to buffer
	char* root_buffer = write_inode(super.root);
	printf("%s\n", root_buffer);
	printf("%d\n", root_buffer);
	strcat( buffer + 10, root_buffer);
	//put superblock and clean up
	ret = put_block( super.super_loc, buffer);
	free( root_buffer);
	free( buffer);
	if(ret<0) return ret;
	return 0;}

int get_superblock() {
	char* buffer = malloc(128 * sizeof(char));
	int i= 0;
	//get superblock
	int ret = put_block( super.super_loc, buffer);
	if(ret<0){
		free( buffer);
		return ret;}
	//read the integer fields from buffer
	i+= get_bytes( buffer + 0, (int*)&( super.blockSize));
	i+= get_bytes( buffer + 2, (int*)&( super.blockCount));
	i+= get_bytes( buffer + 4, (int*)&( super.super_loc));
	i+= get_bytes( buffer + 6, (int*)&( super.openFileTable_loc));
	i+= get_bytes( buffer + 8, (int*)&( super.freeBlockTable_loc));
	//read root from buffer
	super.root = read_inode( buffer + 10);
	free( buffer);
	return 0;}
