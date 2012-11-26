#include <stdio.h>
#include <stdlib.h>
main(){
	int i;
	for(i = 0; i<8; i++)
		printf((char*)&(128>>i));
	printf("\n");
	for(i = 0; i<8; i++)
		printf("%d ",255-(128>>i));
	printf("\n");}
