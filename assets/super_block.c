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
	return put_superblock();}

int put_superblock(Superblock superblock){
	char* buffer = malloc(128 * sizeof(char));
	int i= 0;
	i+= put_bytes(buffer,i,super.blockSize);
	i+= put_bytes(buffer,i,super.blockCount);
	i+= put_bytes(buffer,i,super.super_loc);
	i+= put_bytes(buffer,i,super.openFileTable_loc);
	i+= put_bytes(buffer,i,super.freeBlockTable_loc);
	char* root_buffer = write_inode(super.root);
	strcpy(

int get_superblock() {
	char* buffer = malloc(128 * sizeof(char));
	
}

int put_bytes(char* s, int i, int bytes){
	s[i] = bytes/128;
	s[i+1] = bytes%128;
	return 2;}

int get_bytes(char* s, int i, int* bytes){
	bytes = s[i]*128 + s[i+1];
	return 2;}
