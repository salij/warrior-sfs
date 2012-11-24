#include "inode.h"

int write_inode(inode i);
inode read_inode(int block_index);
int write_itable(inode* t);
inode* read_itable(int block_index);
