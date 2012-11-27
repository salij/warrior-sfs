#include "../assets.h"
#include "../assets/inode.h"
#include <stdio.h>
main(){
	inode i ={
		.index = 3,
		.size = 1,
		.type = 0};
	i.name = malloc(4*sizeof(char));
	i.name = "root";
	char* c = write_inode(i);
	printf("%s",c);
	
	inode i ={
		.index = 0,
		.size = 0,
		.type = 0};
	i.name = malloc(4*sizeof(char));
	i.name = "\0\0\0\0";
	i = read_inode(c);
	printf("%d %d %d %s\n",
		i.index, i.size, i.type, i.name);
}
