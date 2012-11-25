#include "inode.h"

char* write_inode(inode i){//reliably converts inodes into cstrings
	int name_length = strlen(i.name);
	char* result = malloc((4+name_length)* sizeof(char));
	result[0] = i.index;
	result[1] = i.size;
	result[2] = i.type;
	result[3] = name_length;
	for(int j = 0; j<name_length; j++)
		result[4+j] = i.name[j];
	return result;}
inode read_inode(char* s){//reliably converts cstrings into inodes
	inode i;
	i.index = s[0];
	i.size = s[1];
	i.type = s[2]
	int name_length = (int) s[3];
	i.name = malloc(name_length*sizeof(char));
	for(int j = 0; j<name_length; j++)
		i.name[j] = s[4+j];
	return inode;}
int write_itable(char* result, inode* t, int t_size, int size_alloc);
	char* buffer = malloc(sizeof(char)*size_alloc);
	char* inode_string;
	for(int j = 0; j<t_size; j++){
		
int read_itable(char* s, inode* t),
	free(t);
	int s_size = strlen(s);
	int t_size = s_size/10;//minimum possible number of elements
	t = malloc(sizeof(inode)*t_size);
	int s_i = 0;//current index of s
	
	while (s_i<s_size){
		
	