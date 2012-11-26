#include "free_block_table.h"

int set_free(int block_num){//set the block indexed by block_num to free
	char* block_buff = malloc(sizeof(char)*128);
	int table_block_num = super.freeBlockTable_loc;
	int ret = get_block(table_block_num,block_buff);
	if (ret<0) return ret;
	//find and change the bit representing the requested block
	int loc = block_num/8;
	int mod = block_num%8;
	char byte = block_buff[loc];
	byte |= (128>>mod);
	//put the byte back into the table's block and write it
	block_buff[loc] = byte;
	ret = put_block(table_block_num,block_buff);
	return ret<0?ret:0;}

int set_used(int block_num){//set the block indexed by block_num to used
	char* block_buff = malloc(sizeof(char)*128);
	int table_block_num = super.freeBlockTable_loc;
	int ret = get_block(table_block_num,block_buff);
	if (ret<0) return ret;
	//find and change the bit representing the requested block
	int loc = block_num/8;
	int mod = block_num%8;
	char byte = block_buff[loc];
	byte &= 255-(128>>mod);
	//put the byte back into the table's block and write it
	block_buff[loc] = byte;
	ret = put_block(table_block_num,block_buff);
	free(block_buff);
	return ret<0?ret:0;}

int find_free(int size){//size in blocks
	if (size<1) return -1;
	//setup
	int block_buff_size = 128;
	char* block_buff = malloc(sizeof(char)*block_buff_size);
	int table_block_num = super.freeBlockTable_loc;
	int ret = get_block(table_block_num,block_buff);
	if (ret<0) return ret;
	int loc = 0;
	int ubound = block_buff_size - size + 1;
	int bit = 0;
	int n_free = 0;
	char byte = block_buff[loc];
	//search
	while((8*loc + bit) < ubound){
		if(byte & (128>>bit) > 0) n_free++;
		loc += ++bit / 8;
		bit %= 8;
		if(n_free >= size){
			free(block_buff);
			return 8*loc + bit - n_free;}
		if(bit == 0)
			byte = block_buff[loc];}
	free(block_buff);
	return -1;}

int balloc(int size){//allocates blocks
	int block_num = find_free(size);
	if (block_num<0) return block_num;
	char* zero_block = calloc(128,sizeof(char));
		//must be calloc, ensures zeros
	int i;
	int ret;
	for( i=0; i<size; i++){
		ret = put_block(block_num+i,zero_block);
		if (ret<0){
			free(zero_block);
			return ret;}
		ret = set_used(block_num+i);
		if (ret<0){
			free(zero_block);
			return ret;}}
	free(zero_block);
	return block_num;}
	
int bfree(int block_num, int size){
	int i;
	int ret;
	for(i = 0; i<size; i++){
		ret = set_free(block_num + i);
		if(ret<0) return ret;}
	return 0;}

