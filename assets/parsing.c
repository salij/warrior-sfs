#include "parsing.h"


int parse(char* s, inode* dest){
	int length = strlen(s);
	free (dest);
	if (length <=0)
		return -1;
	else if ( length ==1)
		if(s[0]=='/'){
			dest = (inode*)&(super.root);
			return 0;}
		else
			return -1;
	else {
		return parse_it(s+1,dest,super.root);}}

int parse_it(char* s, inode* dest, inode i);/*{
	char* dref = strchr(s,'/');
	int length = dref-s;*/
