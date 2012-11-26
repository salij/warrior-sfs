#include <stdio.h>
main(){
	short i = (1<<14) -1;
	char a = (i/128);
	char b = (i%128);
	printf("%d %d %d %d\n",i,a,b,a*128+b);}
