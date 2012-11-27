#include "blockio.h"
#include "../assets.h"

/*
*@param	int fd			passes the close function the file descriptor number
*@param open_i_block	passes the file descriptor to the open_i_block
*
*int sfs_close function closes a block. If the file that is passed into open_i_node returns true it is open, and then changed to false. Returns true to system to confirm closed. Otherwise, the file isn't open and returns true, that it's closed, to system.
*/
int sfs_close(int fd){
	if(open_i_block[fd].valid){//open_i_block, right variable names???
		open_i_block[fd].valid=0;
		return 1;
	}else{
	return 1;}
