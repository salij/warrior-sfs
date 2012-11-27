#include "blockio.h"
#include "../assets.h"

int sfs_delete(char *pathname){

	char *path_name_ptr = pathname;	

	if(file.type == 0){//if file is a regular file
		//get reference counter
		if(/*reference counter*/ > 0){
			printf("There was an error\n");
		}else{
			//release all blocks of the regular file
			//set file pointer to 0
			*path_name_ptr->0;		
		}
	}
	if(file.type == 1){//if file is a directory file
		//get the file, path
		if(/*directory != empty*/){
			printf("There was an error\n");	
		}
		//get reference counter of file
		if(/*reference counter*/ > 0){
			printf("There was an error");
		}else{
			//release all blocks of the regular file
			//set file pointer to 0
		}
	//get file of parent directory
	//erase the directory entry of the deleted file
	//put the parent directory file back to the disk
	}
}
