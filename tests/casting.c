#include <stdio.h>
#include <stdlib.h>
main(){
	short i = 512;//max (1<<14) -1;
	char* l = malloc(10);
	l[0] = (i/128);
	l[1] = (i%128);
	printf("%d %d %d %d\n",i,l[0],l[1],l[0]*128+l[1]);}
