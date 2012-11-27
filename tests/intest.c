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
}
