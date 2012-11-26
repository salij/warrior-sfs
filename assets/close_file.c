#include "blockio.h"
#include "../assets.h"

int sfs_close(int fd){
	if(open_i_block[fd].valid){
		open_i_block[fd].valid=0;
		return 1;
	}else{
	return 1;}
